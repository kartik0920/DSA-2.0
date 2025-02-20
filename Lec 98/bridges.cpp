#include <bits/stdc++.h>
#include <iostream>
using namespace std;

void dfs(int node, int parent, unordered_map<int, list<int>> &adj, vector<int> &low, vector<int> &disc,
         unordered_map<int, bool> &vis, int &timer, vector<vector<int>> &ans)
{
    vis[node] = 1;
    disc[node] = low[node] = timer++;

    for (auto nbr : adj[node])
    {
        if (nbr == parent)
        {
            continue;
        }

        if (!vis[nbr])
        {
            dfs(nbr, node, adj, low, disc, vis, timer, ans);
            low[node] = min(low[node], low[nbr]);

            if (low[nbr] > disc[node])
            {
                ans.push_back({node, nbr});
            }
        }
        else
        {
            low[node] = min(low[node], disc[nbr]);
        }
    }
}

vector<vector<int>> solve(int v, vector<vector<int>> edges)
{
    unordered_map<int, list<int>> adj;
    for (auto i : edges)
    {
        int u = i[0], v = i[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<vector<int>> ans;
    vector<int> low(v, -1);
    vector<int> disc(v, -1);
    unordered_map<int, bool> vis;
    int parent = -1;
    int timer = 0;
    for (int i = 0; i < v; i++)
    {
        if (!vis[i])
        {
            dfs(i, parent, adj, low, disc, vis, timer, ans);
        }
    }
    return ans;
}

int main()
{
    int v = 5;
    vector<vector<int>> edges = {
        {0, 1},
        {1, 2},
        {0, 2},
        {0, 3},
        {3, 4}};

    vector<vector<int>> ans = solve(v, edges);

    for (auto i : ans)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}