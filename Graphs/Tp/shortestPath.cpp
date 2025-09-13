#include <bits/stdc++.h>
#include <iostream>
using namespace std;

vector<int> shortesrPath(int n, vector<vector<int>> edges, int src = 1, int dest = 8)
{
    unordered_map<int, list<int>> adj;
    for (auto i : edges)
    {
        int u = i[0], v = i[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<bool> vis(n, 0);
    vector<int> parent(n, -1);
    queue<int> q;
    q.push(src);
    vis[src] = 1;

    while (!q.empty())
    {
        int front = q.front();
        q.pop();
        for (auto i : adj[front])
        {
            if (!vis[i])
            {
                parent[i] = front;
                vis[i] = 1;
                q.push(i);
            }
        }
    }

    int curr = dest;
    vector<int> arr;
    while (curr != src)
    {
        arr.push_back(curr);
        curr = parent[curr];
    }
    arr.push_back(src);

    reverse(arr.begin(), arr.end());
    return arr;
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

    vector<int> arr = shortesrPath(n, edges, 1, 8);
    for (auto i : arr)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}