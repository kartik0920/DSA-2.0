#include <bits/stdc++.h>
#include <iostream>
using namespace std;

void dfs(int node, vector<bool> &vis, stack<int> &st, unordered_map<int, list<int>> adj)
{
    vis[node] = 1;

    for (auto i : adj[node])
    {
        if (!vis[i])
        {
            dfs(i, vis, st, adj);
        }
    }
    st.push(node);
}

vector<int> topoSort(int n, vector<vector<int>> edges)
{
    unordered_map<int, list<int>> adj;
    for (auto i : edges)
    {
        int u = i[0], v = i[1];
        adj[u].push_back(v);
    }

    stack<int> st;
    vector<bool> vis(n + 1, 0);

    for (int i = 1; i < n; i++)
    {
        if (!vis[i])
        {
            dfs(i, vis, st, adj);
        }
    }

    vector<int> ans;
    while (!st.empty())
    {
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
}

int main()
{
    int n = 6;
    vector<vector<int>> edges = {
        {1, 2},
        {1, 3},
        {2, 4},
        {3, 4},
        {4, 5},
        {4, 6},
        {5, 6}};

    vector<int> arr = topoSort(n, edges);
    for (auto i : arr)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}