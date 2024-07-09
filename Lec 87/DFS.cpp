#include <bits/stdc++.h>
#include <iostream>
using namespace std;

void oDFS(int i, unordered_map<int, bool> &visited, unordered_map<int, list<int>> adj, vector<int> &component)
{
    component.push_back(i);
    visited[i] = 1;

    for (auto k : adj[i])
    {
        if (!visited[k])
        {
            oDFS(k, visited, adj, component);
        }
    }
}

vector<vector<int>> DFS(int V, int E, unordered_map<int, list<int>> adj)
{
    unordered_map<int, bool> visited;
    vector<vector<int>> ans;
    for (int i = 0; i < V; i++)
    {
        vector<int> compoment;
        if (!visited[i])
        {
            oDFS(i, visited, adj, compoment);
        }
        ans.push_back(compoment);
    }
    return ans;
}
int main()
{
    int V, E;
    cout << "Enter V:";
    cin >> V;
    cout << "Enter E:";
    cin >> E;
    unordered_map<int, list<int>> adj;
    for (int i = 0; i < E; i++)
    {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<vector<int>> arr = DFS(V, E, adj);
    for (auto i : arr)
    {
        for (auto j : i)
        {
            cout << j << ' ';
        }
        cout << endl;
    }
    return 0;
}