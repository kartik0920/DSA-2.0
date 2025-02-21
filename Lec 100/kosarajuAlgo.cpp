#include <bits/stdc++.h>
#include <iostream>
using namespace std;

void topoSort(int node, unordered_map<int, bool> &vis, unordered_map<int, list<int>> adj, stack<int> &st)
{
    vis[node] = 1;
    for (auto nbr : adj[node])
    {
        if (!vis[nbr])
        {
            topoSort(nbr, vis, adj, st);
        }
    }
    st.push(node);
}

void dfs(int node, unordered_map<int, list<int>> transpose, unordered_map<int, bool> &vis, vector<int> &temp)
{
    vis[node] = 1;
    temp.push_back(node);

    for (auto nbr : transpose[node])
    {
        if (!vis[nbr])
        {
            dfs(nbr, transpose, vis, temp);
        }
    }
}

vector<vector<int>> stronglyConnected(int n, vector<vector<int>> edges)
{
    // step 1 create adj list
    unordered_map<int, list<int>> adj;
    for (auto i : edges)
    {
        int u = i[0], v = i[1];
        adj[u].push_back(v);
    }

    // step 2 topo sort
    stack<int> st;
    unordered_map<int, bool> vis;
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            topoSort(i, vis, adj, st);
        }
    }

    // step 3 transpose of edges
    unordered_map<int, list<int>> transpose;
    for (int i = 0; i < n; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        vis[i] = 0;
        transpose[v].push_back(u);
    }

    // dfs call
    vector<vector<int>> ans;
    while (!st.empty())
    {
        vector<int> temp;
        int top = st.top();
        st.pop();
        if (!vis[top])
        {
            dfs(top, transpose, vis, temp);
        }
        if (!temp.empty())
            ans.push_back(temp);
    }

    return ans;
}

int main()
{
    int n = 5;
    vector<vector<int>> edges = {
        {1, 0},
        {0, 2},
        {2, 1},
        {2, 3},
        {3, 4}};

    vector<vector<int>> ans = stronglyConnected(n, edges);

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