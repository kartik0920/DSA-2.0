#include <bits/stdc++.h>
#include <iostream>
using namespace std;

bool dfs(int node, int parent, unordered_map<int, bool> &vis, unordered_map<int, list<int>> adj)
{
    vis[node] = 1;

    for (auto nbr : adj[node])
    {
        if (vis[nbr] && parent != nbr)
        {
            return 1;
        }
        else if (!vis[nbr])
        {
            bool x = dfs(nbr, node, vis, adj);
            return x;
        }
    }
}

bool isCyclic(int n, vector<vector<int>> edges)
{
    // step 1 create adj list
    unordered_map<int, list<int>> adj;
    for (auto i : edges)
    {
        int u = i[0], v = i[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    unordered_map<int, bool> vis;
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            bool check = dfs(i, -1, vis, adj);

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
    int n = 9;
    vector<vector<int>> edges = {
        {1, 2},
        {3, 2},
    };
    // {4, 5},
    // {5, 7},
    // {7, 8},
    // {8, 6},
    // {5, 6},
    // {8, 9}};

    cout << isCyclic(n, edges) << endl;
    return 0;
}