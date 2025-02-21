#include <bits/stdc++.h>
#include <iostream>
using namespace std;

void solve(int node, unordered_map<int, bool> &vis, unordered_map<int, list<int>> adj, vector<int> &ans)
{
    vis[node] = 1;
    ans.push_back(node);

    for (auto nbr : adj[node])
    {
        if (!vis[nbr])
        {
            solve(nbr, vis, adj, ans);
        }
    }
}

vector<int> DFS(int v, vector<vector<int>> edges)
{
    unordered_map<int, list<int>> adj;
    for (auto i : edges)
    {
        int u = i[0], v = i[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> ans;
    unordered_map<int, bool> vis;
    for (int i = 0; i < v; i++)
    {
        if (!vis[i])
        {
            solve(i, vis, adj, ans);
        }
    }
    return ans;
}

int main()
{
    int n = 6;
    vector<vector<int>> edges = {
        {0, 4},
        {2, 4},
        {1, 4},
        {1, 5},
        {3, 5},
        {3, 2},
    };

    vector<int> arr = DFS(n, edges);

    for (auto i : arr)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}