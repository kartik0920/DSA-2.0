#include <bits/stdc++.h>
#include <iostream>
using namespace std;

void dfs(int node, vector<bool> &vis, unordered_map<int, list<int>> adj, stack<int> &st)
{
    vis[node] = 1;

    for (auto i : adj[node])
    {
        if (!vis[i])
        {
            dfs(i, vis, adj, st);
        }
    }
    st.push(node);
}

vector<int> topo(int n, vector<vector<int>> edges)
{
    unordered_map<int, list<int>> adj;
    for (auto i : edges)
    {
        int u = i[0], v = i[1];
        adj[u].push_back(v);
    }
    vector<bool> vis(n);
    stack<int> st;

    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            dfs(i, vis, adj, st);
        }
    }
    vector<int> arr;
    while (!st.empty())
    {
        arr.push_back(st.top());
        st.pop();
    }
    return arr;
}

int main()
{
    int n = 4;
    vector<vector<int>> edges = {
        {0, 1},
        {0, 3},
        {1, 2},
        {3, 2}};

    vector<int> arr = topo(n, edges);
    for (auto i : arr)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}