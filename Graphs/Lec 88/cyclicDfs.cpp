#include <bits/stdc++.h>
#include <iostream>
using namespace std;

bool checkDFS(int i, int parent, unordered_map<int, list<int>> adjlist, unordered_map<int, bool> &visited)
{
    visited[i] = 1;
    for (auto j : adjlist[i])
    {
        if (visited[j] && j != parent)
        {
            return 1;
        }
        else if (!visited[j])
        {
            visited[j] = 1;
            bool check = checkDFS(j, i, adjlist, visited);
        }
    }
    return 0;
}

bool isCyclic(int n, vector<vector<int>> edges)
{
    unordered_map<int, bool> visited;
    unordered_map<int, list<int>> adjlist;
    for (auto i : edges)
    {
        int u = i[0];
        int v = i[1];

        adjlist[u].push_back(v);
        adjlist[v].push_back(u);
    }

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            bool check = checkDFS(i, -1, adjlist, visited);
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
    int n = 6;
    vector<vector<int>> edges = {
        {0, 4},
        {4, 2},
        {2, 3},
        {3, 5},
        {5, 1},
        {1, 0}};
    // int n = 5;
    // vector<vector<int>> edges = {
    //     {0, 1},
    //     {1, 2},
    //     {2, 4},
    //     {2, 3},
    //     {4, 3}};

    cout << isCyclic(n, edges) << endl;

    return 0;
}