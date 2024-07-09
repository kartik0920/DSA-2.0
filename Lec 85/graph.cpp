#include <bits/stdc++.h>
#include <iostream>
using namespace std;
template <typename T>
class Graph
{
    unordered_map<T, list<T>> adj;

public:
    // if(x==0)->directed graph
    // else undirected graph
    void AddEdge(T u, T v, bool x)
    {
        adj[u].push_back(v);
        if (x)
        {
            adj[v].push_back(u);
        }
    }

    void printGraphList()
    {
        for (auto i : adj)
        {
            cout << i.first << ':';
            for (auto j : i.second)
            {
                cout << j << ' ';
            }
            cout << endl;
        }
    }
};

int main()
{
    int n = 0, m = 0;
    // here n and m are the no of the vertices and edges of the graph
    Graph<int> g;
    cout << "Enter the no of nodes";
    cin >> n;
    cout << "Enter the no of edges";
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;

        g.AddEdge(u, v, 1);
    }

    g.printGraphList();
    return 0;
}