#include <bits/stdc++.h>
#include <iostream>
using namespace std;

vector<vector<int>> prims(int n, vector<vector<int>> &edges)
{
    unordered_map<int, list<pair<int, int>>> adj;
    for (auto i : edges)
    {
        int u = i[0], v = i[1], w = i[2];
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    vector<int> dist(n, INT_MAX);
    vector<int> parent(n, -1);
    vector<bool> mst(n, 0);

    dist[0] = 0;
    for (int i = 0; i < n; i++)
    {
        int mini = INT_MAX;
        int u;

        for (int j = 0; j < n; j++)
        {
            if (!mst[j] && dist[j] < mini)
            {
                mini = dist[j];
                u = j;
            }
        }
        mst[u] = 1;

        for (auto k : adj[u])
        {
            int v = k.first;
            int w = k.second;
            if (!mst[v] && w < dist[v])
            {
                dist[v] = w;
                parent[v] = u;
            }
        }
    }

    int sum = 0;
    for (auto i : dist)
    {
        sum += i;
    }
    cout << "Sum is : " << sum << endl;

    vector<vector<int>> ans;
    for (int i = 1; i < n; i++)
    {
        ans.push_back({i, parent[i], dist[i]});
    }
    return ans;
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

    vector<vector<int>> mst = prims(n, edges);

    for (auto i : mst)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}