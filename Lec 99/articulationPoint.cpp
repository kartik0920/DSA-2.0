#include <bits/stdc++.h>
#include <iostream>
using namespace std;

void dfs(int node, int parent, vector<int> &dsc, vector<int> &low, unordered_map<int, bool> &vis, int &timer,
         unordered_map<int, list<int>> adj, vector<int> &ans)
{
    vis[node] = 1;
    dsc[node] = low[node] = timer++;

    int child = 0;
    for (auto nbr : adj[node])
    {
        if (nbr == parent)
        {
            continue;
        }

        if (!vis[nbr])
        {
            dfs(nbr, node, dsc, low, vis, timer, adj, ans);
            low[node] = min(low[node], low[nbr]);

            if (low[nbr] >= dsc[node] && parent != -1)
            {
                ans.push_back(node);
            }
            child++;
        }
        else
        {
            low[node] = min(low[node], dsc[nbr]);
        }
    }

    if (parent == -1 && child > 1)
    {
        ans.push_back(node);
    }
}

vector<int> solve(int v, vector<vector<int>> edges)
{
    vector<int> ans;
    unordered_map<int, list<int>> adj;

    for (auto i : edges)
    {
        int u = i[0], v = i[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> dsc(v, -1);
    vector<int> low(v, -1);
    unordered_map<int, bool> vis;
    int parent = -1;
    int timer = 0;

    for (int i = 0; i < v; i++)
    {
        if (!vis[i])
        {
            dfs(i, parent, dsc, low, vis, timer, adj, ans);
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

    vector<int> ans = solve(v, edges);

    for (auto i : ans)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}