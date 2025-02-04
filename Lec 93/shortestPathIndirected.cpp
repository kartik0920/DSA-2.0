#include <bits/stdc++.h>
#include <iostream>
using namespace std;
void printArr(vector<int> arr)
{
    for (auto i : arr)
    {
        cout << i << " ";
    }
    cout << endl;
}

vector<int> getPath(int n, vector<vector<int>> edges, int s, int e)
{
    unordered_map<int, list<int>> adjList;
    for (auto i : edges)
    {
        int u = i[0], v = i[1];
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    vector<int> ans;
    unordered_map<int, bool> visited;
    unordered_map<int, int> parent;
    queue<int> q;
    q.push(s);
    visited[s] = 1;
    parent[s] = -1;

    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        for (auto i : adjList[node])
        {
            if (!visited[i])
            {
                visited[i] = 1;
                parent[i] = node;
                q.push(i);
            }
        }
    }

    int temp = e;
    ans.insert(ans.begin(), temp);
    while (temp != s)
    {
        temp = parent[temp];
        ans.insert(ans.begin(), temp);
    }
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

    vector<int> shortestPath = getPath(n, edges, 1, 8);
    printArr(shortestPath);
    return 0;
}