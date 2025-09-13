#include <bits/stdc++.h>
#include <iostream>
using namespace std;

bool dfs(int node, vector<bool> &vis, vector<bool> &dfsVis, unordered_map<int, list<int>> &adj)
{
    vis[node] = 1;
    dfsVis[node] = 1;

    for (auto i : adj[node])
    {
        if (!vis[i])
        {
            bool check = dfs(i, vis, dfsVis, adj);
            if (check)
            {
                return 1;
            }
        }
        else if (dfsVis[i])
        {
            return 1;
        }
    }
    dfsVis[node] = 0;
    return 0;
}

bool cycleDetection(int n, vector<vector<int>> edges)
{
    unordered_map<int, list<int>> adj;
    for (auto i : edges)
    {
        int u = i[0], v = i[1];

        adj[u].push_back(v);
    }
    vector<bool> vis(n + 1, 0), dfsVis(n + 1, 0);
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            bool check = dfs(i, vis, dfsVis, adj);
            if (check)
            {
                return 1;
            }
        }
    }
    return 0;
}

int main()
{
    int n = 5;
    vector<vector<int>> edges = {
        {0, 1},
        {1, 2},
        {2, 3},
        {3, 4},
        {4, 2}};

    if (cycleDetection(n, edges))
    {
        cout << "Cycle is present!" << endl;
    }
    else
    {
        cout << "Cycle is abesnt" << endl;
    }
    return 0;
}