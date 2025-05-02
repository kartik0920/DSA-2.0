#include <bits/stdc++.h>
#include <iostream>
using namespace std;

void getBfs(int src, vector<bool> &vis, unordered_map<int, list<int>> adj, vector<int> &ans)
{
    queue<int> q;
    q.push(0);
    vis[0] = 1;
    while (!q.empty())
    {
        int front = q.front();
        q.pop();
        ans.push_back(front);
        for (auto i : adj[front])
        {
            if (!vis[i])
            {
                vis[i] = 1;
                q.push(i);
            }
        }
    }
}

vector<int> BFS(int n, vector<vector<int>> edges)
{
    unordered_map<int, list<int>> adj;
    for (auto i : edges)
    {
        int u = i[0], v = i[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> ans;
    vector<bool> vis(n, 0);
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            getBfs(i, vis, adj, ans);
        }
    }

    return ans;
}
int main()
{
    int n = 5;
    vector<vector<int>> edges = {
        {0, 1},
        {1, 2},
        {2, 3},
        {2, 4}};

    vector<int> arr = BFS(n, edges);
    for (auto i : arr)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}