#include <bits/stdc++.h>
#include <iostream>
using namespace std;

bool dfs(int src, vector<bool> &vis, vector<bool> &dfsVis, unordered_map<int, list<int>> adj)
{
    vis[src] = 1;
    dfsVis[src] = 1;

    for (auto i : adj[src])
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
    dfsVis[src] = 0;
    return 0;
}

bool isCycle(int n, vector<vector<int>> edges)
{
    unordered_map<int, list<int>> adj;
    for (auto i : edges)
    {
        int u = i[0], v = i[1];
        adj[u].push_back(v);
        // adj[v].push_back(u);
    }
    vector<bool> vis(n), dfsVis(n);

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
    int n = 4;
    vector<vector<int>> edges = {
        {1, 2},
        {2, 3},
        {3, 1},
        {0, 1},
        {0, 3}};

    if (isCycle(n, edges))
    {
        cout << "Cycle is Present!" << endl;
    }
    else
    {
        cout << "Cycle is Absent" << endl;
    }
    return 0;
}