#include <bits/stdc++.h>
#include <iostream>
using namespace std;

bool cmp(vector<int> &a, vector<int> &b)
{
    return a[2] < b[2];
}

int findParent(int u, vector<int> &parent)
{
    if (parent[u] == u)
    {
        return u;
    }
    return parent[u] = findParent(parent[u], parent);
}

void unionSet(int u, int v, vector<int> &parent, vector<int> &rank)
{
    u = findParent(u, parent);
    v = findParent(v, parent);

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

int solve(int n, int m, vector<vector<int>> edges)
{
    int ans = 0;
    vector<int> parent(n), rank(n, 0);

    // Parent and Rank was declared
    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
    }
    // sorting edges according to weights
    sort(edges.begin(), edges.end(), cmp);

    for (auto i : edges)
    {
        int u = findParent(i[0], parent);
        int v = findParent(i[1], parent);

        int w = i[2];

        if (u != v)
        {
            ans += w;
            unionSet(u, v, parent, rank);
        }
    }

    return ans;
}
int main()
{
    int n = 5;
    int m = 6;
    vector<vector<int>> edges = {
        {0, 3, 6},
        {0, 1, 2},
        {1, 3, 8},
        {1, 4, 5},
        {1, 2, 3},
        {2, 4, 7}};

    cout << solve(n, m, edges) << endl;

    return 0;
}