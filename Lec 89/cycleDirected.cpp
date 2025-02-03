#include <bits/stdc++.h>
#include <iostream>
using namespace std;

bool solve(int node, unordered_map<int, list<int>> adjlist, unordered_map<int, bool> &visited, unordered_map<int, bool> &dfsvisited)
{
    visited[node] = 1;
    dfsvisited[node] = 1;
    for (auto i : adjlist[node])
    {
        if (!visited[i])
        {
            bool x = solve(i, adjlist, visited, dfsvisited);
            if (x)
            {
                return 1;
            }
        }
        else if (dfsvisited[i])
        {
            return 1;
        }
    }
    dfsvisited[node] = 0;
    return 0;
}

bool checkCycle(int n, vector<vector<int>> edges)
{
    unordered_map<int, list<int>> adjlist;
    for (auto i : edges)
    {
        int u = i[0];
        int v = i[1];
        adjlist[u].push_back(v);
    }

    unordered_map<int, bool> visited, dfsvisited;

    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            bool checkans = solve(i, adjlist, visited, dfsvisited);
            if (checkans)
            {
                return 1;
            }
        }
    }
    return 0;
}

int main()
{
    int n = 8;
    vector<vector<int>> edges = {
        {1, 2},
        {2, 4},
        {4, 5},
        {5, 6},
        {6, 4},
        {2, 3},
        {3, 7},
        {3, 8},
        {8, 7}};

    cout << checkCycle(n, edges) << endl;
    return 0;
}