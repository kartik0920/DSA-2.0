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

void solve(int node, vector<int> &arr, unordered_map<int, bool> &visited, unordered_map<int, list<int>> adjlist)
{
    arr.push_back(node);
    visited[node] = 1;

    for (auto i : adjlist[node])
    {
        if (!visited[i])
        {
            solve(i, arr, visited, adjlist);
        }
    }
}

vector<int> dfs(int n, vector<vector<int>> edges)
{
    unordered_map<int, list<int>> adjlist;
    for (auto i : edges)
    {
        int u = i[0], v = i[1];
        adjlist[u].push_back(v);
        adjlist[v].push_back(u);
    }
    unordered_map<int, bool> visited;
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            solve(i, ans, visited, adjlist);
        }
    }
    return ans;
}

int main()
{
    int n = 5;
    vector<vector<int>> edges = {
        {0, 1},
        {1, 2},
        {2, 4},
        {2, 3},
        {4, 3}};

    vector<int> dfsArr = dfs(n, edges);
    printArr(dfsArr);
    return 0;
}