#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Graph
{

    unordered_map<int, list<int>> adjlist;

public:
    void addEdge(int u, int v, bool isDirected)
    {
        adjlist[u].push_back(v);
        if (isDirected)
        {
            adjlist[v].push_back(u);
        }
    }

    void printGraph()
    {
        for (auto i : adjlist)
        {

            cout << i.first << " -->";
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
    Graph g;
    g.addEdge(0, 1, 0);
    g.addEdge(1, 2, 0);
    g.addEdge(3, 1, 0);
    g.addEdge(4, 1, 0);
    g.addEdge(4, 0, 0);

    g.printGraph();
    return 0;
}