#include <bits/stdc++.h>
#include <iostream>
using namespace std;

void topo(stack<int> &st, vector<bool> &vis, int node, unordered_map<int, list<pair<int, int>>> &adj)
{
    vis[node] = 1;

    for (auto i : adj[node])
    {
        int v = i.first, w = i.second;
        if (!vis[v])
        {
            topo(st, vis, v, adj);
            vis[v] = 1;
        }
    }
    st.push(node);
}

vector<int> shortestPath(int n, vector<vector<int>> edges, int src)
{
    // making adj list
    unordered_map<int, list<pair<int, int>>> adj;
    for (auto i : edges)
    {
        int u = i[0], v = i[1], w = i[2];
        adj[u].push_back({v, w});
    }
    // creating vis array and stack for topological sort
    vector<bool> vis(n, 0);
    stack<int> st;
    topo(st, vis, 0, adj);

    // creating an array with int_max for comparison and making distance
    vector<int> dist(n, INT_MAX);
    dist[src] = 0;

    while (!st.empty())
    {
        int top = st.top();
        st.pop();

        if (dist[top] != INT_MAX) // only change when !INT_MAX
        {
            for (auto i : adj[top]) // Traversing all elements
            {
                int new_dist = dist[top] + i.second; // Formula for new distance
                if (new_dist < dist[i.first])        // If new distance is less than actual then changing the distance
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