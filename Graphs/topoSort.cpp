#include <bits/stdc++.h>
#include <iostream>
using namespace std;

void dfs(int node, unordered_map<int, bool> &vis, unordered_map<int, list<int>> adj, stack<int> &st)
{
    vis[node] = 1;

    for (auto nbr : adj[node])
    {
        if (!vis[nbr])
        {
            dfs(nbr, vis, adj, st);
        }
    }
    st.push(node);
}

vector<int> topoSort(int n, vector<vector<int>> edges)
{
    // create adjlist
    unordered_map<int, list<int>> adj;
    for (auto i : edges)
    {
        int u = i[0], v = i[1];
        adj[u].push_back(v);
    }
    // create stack for saving values and visited for tracking wheter visited or not
    stack<int> st;
    unordered_map<int, bool> vis;
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            dfs(i, vis, adj, st);
        }
    }
    // stroing values in arrays
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
        {3, 4},
        {2, 4},
        {4, 5},
        {4, 6},
        {5, 6}};
    // int n = 4;
    // vector<vector<int>> edges = {
    //     {0, 1},
    //     {0, 3},
    //     {1, 2},
    //     {3, 2}};

    vector<int> arr = topoSort(n, edges);
    for (auto i : arr)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}