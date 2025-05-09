#include <bits/stdc++.h>
#include <iostream>
using namespace std;

vector<int> shortestPath(int n, vector<vector<int>> edges, int src, int dest)
{
    unordered_map<int, list<int>> adj;
    for (auto i : edges)
    {
        int u = i[0], v = i[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<bool> vis(n + 1);
    vector<int> parent(n + 1);
    queue<int> q;

    q.push(src);
    vis[src] = 1;
    parent[src] = -1;

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
        }
    }

    vector<int> ans;
    int curr = dest;
    while (curr != src && curr != -1)
    {
        ans.push_back(curr);
        curr = parent[curr];
    }
    ans.push_back(curr);
    reverse(ans.begin(), ans.end());
    return ans;
}
int main()
{
    int n = 8;
    vector<vector<int>> edges = {
        {1, 2},
        {1, 3},
        {1, 4},
        {2, 5},
        {5, 8},
        {3, 8},
        {4, 6},
        {6, 7},
        {7, 8}};

    vector<int> arr = shortestPath(n, edges, 1, n);
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i];
        if (i < arr.size() - 1)
        {
            cout << '-';
        }
    }
    cout << endl;
    return 0;
}