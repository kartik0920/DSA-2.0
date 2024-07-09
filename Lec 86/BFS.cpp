#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Graph
{
    unordered_map<int, list<int>> AdjList;
    int n, m;
    void oBFS(int i, vector<int> &ans, unordered_map<int, bool> &visited)
    {
        queue<int> q;
        q.push(i);
        while (!q.empty())
        {
            int front = q.front();
            q.pop();
            visited[i] = 1;
            ans.push_back(front);
            for (auto i : AdjList[front])
            {
                if (!visited[i])
                {
                    q.push(i);
                    visited[i] = 1;
                }
            }
        }
    }

public:
    Graph(int n, int m)
    {
        this->n = n;
        this->m = m;
    }
    void AddEdge(int u, int v)
    {
        AdjList[u].push_back(v);
        AdjList[v].push_back(u);
    }

    void printGraph()
    {
        for (auto i : AdjList)
        {
            cout << i.first << ':';
            for (auto j : i.second)
            {
                cout << j << ' ';
            }
            cout << endl;
        }
    }
    vector<int> BFS()
    {
        vector<int> arr;
        unordered_map<int, bool> visited;
        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                oBFS(i, arr, visited);
            }
        }
        return arr;
    }
};
int main()
{
    int n, m;
    cout << "Enter no of vertices:";
    cin >> n;
    cout << "Enter no of edges:";
    cin >> m;
    Graph g(n, m);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        g.AddEdge(u, v);
    }
    g.printGraph();
    vector<int> arr = g.BFS();
    cout << endl;
    cout << arr.size() << endl;
    for (auto i : arr)
    {
        cout << i << ' ';
    }
    return 0;
}