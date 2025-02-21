#include <bits/stdc++.h>
#include <iostream>
using namespace std;

void solve(int node, unordered_map<int, list<int>> adj, unordered_map<int, bool> &vis, vector<int> &ans)
{
    vis[node] = 1;
    queue<int> q;
    q.push(node);

    while (!q.empty())
    {
        int top = q.front();
        q.pop();
        ans.push_back(top);
        for (auto nbr : adj[top])
        {
            if (!vis[nbr])
            {
                q.push(nbr);
                vis[nbr] = 1;
            }
        }
    }
}

vector<int> BFS(int n, vector<vector<int>> edges)
{
    // step 1 make sdj list
    unordered_map<int, list<int>> adj;
    for (auto i : edges)
    {
        int u = i[0], v = i[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    // ans for answer and map for tracking visited or not
    vector<int> ans;
    unordered_map<int, bool> vis;

    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            solve(i, adj, vis, ans);
        }
    }
    return ans;
}

int main()
{
    int n = 5;
    vector<vector<int>> edges = {
        {0, 1},
        {2, 1},
        {2, 4},
        {2, 3},
        {4, 1},
    };

    vector<int> arr = BFS(n, edges);

    for (auto i : arr)
    {
        cout << i << " ";
    }
    return 0;
}