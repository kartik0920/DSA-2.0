#include <bits/stdc++.h>
#include <iostream>
using namespace std;
template <typename T>

class Graph
{
public:
    unordered_map<T, list<T>> adjlist;

    void addEdge(T u, T v, bool direction = 0)
    {
        adjlist[u].push_back(v);
        if (direction)
        {
            adjlist[v].push_back(u);
        }
    }

    void printGraph()
    {
        for (auto i : adjlist)
        {
            cout << i.first << ":";
            for (auto j : i.second)
            {
                cout << j << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    int n, m;

    cout << "Enter no of nodes:";
    cin >> n;
    cout << "Enter no of edges:";
    cin >> m;

    Graph<int> g;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        // add 1 if you want undiredcted graph
        g.addEdge(u, v, 1);
    }

    g.printGraph();
    return 0;
}