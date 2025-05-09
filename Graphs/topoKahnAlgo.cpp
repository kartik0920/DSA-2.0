#include <bits/stdc++.h>
#include <iostream>
using namespace std;

vector<int> topoSort(int n, vector<vector<int>> edges)
{
    unordered_map<int, list<int>> adj;
    for (auto i : edges)
    {
        int u = i[0], v = i[1];
        adj[u].push_back(v);
    }

    vector<int> indegree(n + 1);
    for (auto i : adj)
    {
        for (auto j : i.second)
        {
            indegree[j]++;
        }
    }
    queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        if (indegree[i] == 0)
            q.push(i);
    }

    vector<int> ans;
    while (!q.empty())
    {
        int front = q.front();
        q.pop();
        ans.push_back(front);
        for (auto i : adj[front])
        {
            indegree[i]--;
            if (indegree[i] == 0)
            {
                q.push(i);
            }
        }
    }
    return ans;
}

int main()
{
    int n = 6;
    vector<vector<int>> edges = {
        {1, 2},
        {1, 3},
        {2, 4},
        {3, 4},
        {4, 5},
        {4, 6},
        {5, 6}};

    vector<int> arr = topoSort(n, edges);
    for (auto i : arr)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}