#include <bits/stdc++.h>
#include <iostream>
using namespace std;

bool dfs(int node, unordered_map<int, list<int>> adj, unordered_map<int, bool> &vis, unordered_map<int, bool> &dfsVis)
{
    // marking both as true
    vis[node] = 1;
    dfsVis[node] = 1;
    for (auto nbr : adj[node])
    {
        // checking is node is not visited if not calling it fnuction and return value
        if (!vis[nbr])
        {
            return dfs(nbr, adj, vis, dfsVis);
        }
        // checking for wheter dfs is visited or nor
        else if (vis[nbr] && dfsVis[nbr])
        {
            return 1;
        }
    }
    // backtracking dfsVis=0 for next iteration as we are going back
    dfsVis[node] = 0;
    return 0;
}

bool isCyclic(int v, vector<vector<int>> edges)
{
    // step 1 create adj list
    unordered_map<int, list<int>> adj;
    for (auto i : edges)
    {
        int u = i[0], v = i[1];
        adj[u].push_back(v);
    }

    // step 2 create 2 maps for tracking wheter the node is visited and second for where node is visited in same cycle
    unordered_map<int, bool> vis, dfsVis;
    for (int i = 0; i < v; i++)
    {
        if (!vis[i])
        {
            bool x = dfs(i, adj, vis, dfsVis);
            if (x)
            {
                return 1;
            }
        }
    }
    return 0;
}

int main()
{
    int n = 8;
    vector<vector<int>> edges = {
        {1, 2},
        {2, 3},
        {3, 7},
        {3, 8},
        {8, 7},
        {2, 4},
        {4, 5},
        {5, 6},
        {6, 4}};

    cout << isCyclic(n, edges) << endl;
    return 0;
}