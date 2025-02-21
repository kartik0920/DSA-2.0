#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int shortestPath(int n, vector<vector<int>> edges, int src, int dest)
{
    int m = edges.size();
    vector<int> dist(n + 1, INT_MAX);
    dist[src] = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int u = edges[j][0];
            int v = edges[j][1];
            int wt = edges[j][2];

            if (dist[u] != 1e9 && dist[u] + wt < dist[v])
            {
                dist[v] = dist[u] + wt;
            }
        }
    }

    bool check = 0;
    for (int j = 0; j < m; j++)
    {
        int u = edges[j][0];
        int v = edges[j][1];
        int wt = edges[j][2];
        if (dist[j] != 1e9 && dist[u] + wt < dist[v])
        {
            check = 1;
        }
    }

    return check ? -1 : dist[dest];
}

int main()
{
    int n = 3;
    vector<vector<int>> edges = {
        {1, 2, 2},
        {2, 3, -1},
        {1, 3, 2}};

    int src = 1, dest = 3;

    cout << shortestPath(n, edges, src, dest) << endl;
    return 0;
}