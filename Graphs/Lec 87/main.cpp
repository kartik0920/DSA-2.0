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

void prepareList(vector<vector<int>> edges, unordered_map<int, list<int>> &adjlist)
{
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adjlist[u].push_back(v);
        adjlist[v].push_back(u);
    }
}

void dfs(int i, unordered_map<int, bool> &visited, unordered_map<int, list<int>> adjList, vector<int> &ans)
{
    ans.push_back(i);
    visited[i] = 1;

    for (auto j : adjList[i])
    {
        if (!visited[j])
        {
            dfs(j, visited, adjList, ans);
        }
    }
}

vector<int> solve(int n, vector<vector<int>> edges)
{
    unordered_map<int, list<int>> adjList;
    unordered_map<int, bool> visited;
    prepareList(edges, adjList);
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {

        if (!visited[i])
        {

            dfs(i, visited, adjList, ans);
        }
    }
    return ans;
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
        {1, 4}};
    // int n = 5;
    // vector<vector<int>> edges = {
    //     {0, 1},
    //     {1, 2},
    //     {2, 4},
    //     {2, 3},
    //     {4, 3}};

    vector<int> arr = solve(n, edges);
    printArr(arr);

    return 0;
}