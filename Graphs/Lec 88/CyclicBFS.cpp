#include <bits/stdc++.h>
#include <iostream>
using namespace std;

bool BFScheck(int i, unordered_map<int, bool> &visited, unordered_map<int, list<int>> adjlist)
{
    unordered_map<int, int> parent;
    queue<int> q;
    q.push(i);
    parent[i] = -1;
    visited[i] = 1;

    while (!q.empty())
    {
        int front = q.front();
        q.pop();

        for (auto i : adjlist[front])
        {
            if (visited[i] && i != parent[front])
            {
                return 1;
            }
            if (!visited[i])
            {
                q.push(i);
                parent[i] = front;
                visited[i] = 1;
            }
        }
    }
    return 0;
}

bool isCyclic(int n, vector<vector<int>> edges)
{
    unordered_map<int, list<int>> adjlist;
    for (auto i : edges)
    {
        int u = i[0];
        int v = i[1];

        adjlist[u].push_back(v);
        adjlist[v].push_back(u);
    }
    unordered_map<int, bool> visited;

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            bool check = BFScheck(i, visited, adjlist);
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
    };
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