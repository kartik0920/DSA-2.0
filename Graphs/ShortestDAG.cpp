#include <bits/stdc++.h>
#include <iostream>
using namespace std;

void dfs(stack<int> &st, unordered_map<int, list<pair<int, int>>> &adj, vector<bool> &vis, int node)
{
    vis[node] = 1;

    for (auto i : adj[node])
    {
        int x = i.first;
        int w = i.second;
        if (!vis[x])
        {
            dfs(st, adj, vis, x);
            vis[x] = 1;
            // cout << 1;
        }
    }
    st.push(node);
}

vector<int> shortestPath(int n, vector<vector<int>> edges, int src)
{
    unordered_map<int, list<pair<int, int>>> adj;

    for (auto i : edges)
    {
        int u = i[0], v = i[1], w = i[2];

        adj[u].push_back({v, w});
    }
    stack<int> st;
    vector<bool> vis(n + 1);
    dfs(st, adj, vis, 0);

    vector<int> dist(n, INT_MAX);

    dist[src] = 0;
    while (!st.empty())
    {
        int top = st.top();
        st.pop();
        if (dist[top] != INT_MAX)
        {
            for (auto i : adj[top])
            {
                int new_dist = dist[top] + i.second;
                if (new_dist < dist[i.first])
                {
                    dist[i.first] = new_dist;
                }
            }
        }
    }
    return dist;
}
int main()
{
    int n = 6;
    vector<vector<int>> edges = {
        {0, 1, 5},
        {0, 2, 3},
        {1, 2, 2},
        {1, 3, 6},
        {2, 3, 7},
        {2, 5, 2},
        {2, 3, 7},
        {2, 4, 4},
        {3, 4, -1},
        {4, 5, -2}};

    int src = 1;
    vector<int> arr = shortestPath(n, edges, src);
    for (auto i : arr)
    {
        cout << i << " ";
    }
    return 0;
}