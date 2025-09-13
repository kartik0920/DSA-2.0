#include <bits/stdc++.h>
#include <iostream>
using namespace std;

bool bfs(int src, int n, vector<bool> &vis, unordered_map<int, list<int>> adj)
{
    queue<int> q;
    vector<int> parent(n);
    q.push(src);
    parent[src] = -1;
    vis[src] = 1;

    while (!q.empty())
    {
        int front = q.front();
        q.pop();

        for (auto i : adj[front])
        {
            if (!vis[i])
            {
                vis[i] = 1;
                parent[i] = front;
                q.push(i);
            }
            else if (vis[i] && parent[front] != i)
            {
                return 1;
            }
        }
    }
    return 0;
}

bool isCycle(int n, vector<vector<int>> edges)
{
    unordered_map<int, list<int>> adj;
    for (auto i : edges)
    {
        int u = i[0], v = i[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<bool> vis(n, 0);

    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            bool check = bfs(i, n, vis, adj);
            if (check)
            {
                return 1;
            }
        }
    }
    return 0;
}

int main()
{
    int n = 5;
    vector<vector<int>> edges = {
        {1, 3},
        {1, 2},
        {2, 4},
        // {3, 4},
        {4, 5}};

    if (isCycle(n, edges))
    {
        cout << "Cycle is present" << endl;
    }
    else
    {
        cout << "Cycle is absent" << endl;
    }
    return 0;
}