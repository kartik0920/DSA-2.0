#include <bits/stdc++.h>
#include <iostream>
using namespace std;

bool dfs(int src, int parent, vector<bool> &vis, unordered_map<int, list<int>> adj)
{
    vis[src] = 1;
    for (auto i : adj[src])
    {
        if (!vis[i])
        {
            bool check = dfs(i, src, vis, adj);
            if (check)
            {
                return 1;
            }
        }
        else if (parent != i)
        {
            return 1;
        }
    }
    return 0;
}

bool isCycle(int n, vector<vector<int>> edges)
{
    unordered_map<int, list<int>> adj;
    for (auto i : edges)
    {
        int u = i[0], v = i[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<bool> vis(n, 0);

    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            int parent = -1;
            bool check = dfs(i, parent, vis, adj);
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
        {1, 3},
        {1, 2},
        {2, 4},
        // {3, 4},
        {4, 5}};

    if (isCycle(n, edges))
    {
        cout << "Cycle is present" << endl;
    }
    else
    {
        cout << "Cycle is absent" << endl;
    }
    return 0;
}