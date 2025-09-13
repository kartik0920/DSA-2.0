#include <bits/stdc++.h>
#include <iostream>
using namespace std;

bool cmp(vector<int> a, vector<int> b)
{
    return a[2] < b[2];
}

int findParent(vector<int> &parent, int node)
{
    if (parent[node] == node)
    {
        return node;
    }

    parent[node] = findParent(parent, parent[node]);
    return parent[node];
}

void setUnion(int u, int v, vector<int> &parent, vector<int> &rank)
{
    u = findParent(parent, u);
    v = findParent(parent, v);
    if (rank[u] > rank[v])
    {
        parent[v] = u;
    }
    else if (rank[u] < rank[v])
    {
        parent[u] = v;
    }
    else
    {
        parent[v] = u;
        rank[u]++;
    }
}

int mst(int n, vector<vector<int>> &edges)
{
    sort(edges.begin(), edges.end(), cmp);
    vector<int> parent(n), rank(n);
    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
    }
    int total = 0;
    for (int i = 0; i < edges.size(); i++)
    {
        int u = findParent(parent, edges[i][0]);
        int v = findParent(parent, edges[i][1]);
        int wt = edges[i][2];
        if (u != v)
        {
            total += wt;
            setUnion(u, v, parent, rank);
        }
    }
    return total;
}

int main()
{
    int n = 5;
    vector<vector<int>> edges = {
        {0, 1, 2},
        {0, 3, 6},
        {1, 3, 8},
        {1, 4, 5},
        {1, 2, 3},
        {4, 2, 7}};

    cout << mst(n, edges) << endl;

    // 16

    return 0;
}