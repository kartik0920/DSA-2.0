#include <bits/stdc++.h>
#include <iostream>
using namespace std;

bool isCycle(int n, vector<vector<int>> edges)
{
    unordered_map<int, list<int>> adj;
    for (auto i : edges)
    {
        int u = i[0], v = i[1];
        adj[u].push_back(v);
    }
    int cnt = 0;
    vector<int> inDegree(n, 0);
    for (auto i : adj)
    {
        for (auto j : i.second)
        {
            inDegree[j]++;
        }
    }
    vector<bool> vis(n, 0);
    queue<int> q;
    for (int i = 0; i < n; i++)
    {
        if (inDegree[i] == 0)
        {
            q.push(i);
            vis[i] = 1;
        }
    }

    while (!q.empty())
    {
        int front = q.front();
        q.pop();
        cnt++;
        for (auto i : adj[front])
        {
            inDegree[i]--;
            if (inDegree[i] == 0)
            {
                q.push(i);
            }
        }
    }
    return cnt != n;
}
int main()
{
    int n = 4;
    vector<vector<int>> edges = {
        {1, 2},
        {2, 3},
        // {3, 1},
        {0, 1},
        {0, 3}};

    if (isCycle(n, edges))
    {
        cout << "Cycle is Present!" << endl;
    }
    else
    {
        cout << "Cycle is Absent" << endl;
    }
    return 0;
}