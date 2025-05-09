#include <bits/stdc++.h>
#include <iostream>
using namespace std;

void getDFS(int node, vector<bool> &vis, unordered_map<int, list<int>> adj, vector<int> &arr)
{
    vis[node] = 1;
    arr.push_back(node);

    for (auto i : adj[node])
    {
        if (!vis[i])
        {
            getDFS(i, vis, adj, arr);
        }
    }
}

vector<int> DFS(int n, vector<vector<int>> edges)
{
    unordered_map<int, list<int>> adj;
    for (auto i : edges)
    {
        int u = i[0], v = i[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> arr;
    vector<bool> vis(n);
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            getDFS(i, vis, adj, arr);
        }
    }
    return arr;
}

int main()
{
    int n = 6;
    vector<vector<int>> edges = {
        {0, 4},
        {4, 2},
        {2, 3},
        {3, 5},
        {5, 1},
        {1, 4}};

    vector<int> arr = DFS(n, edges);
    for (auto i : arr)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}