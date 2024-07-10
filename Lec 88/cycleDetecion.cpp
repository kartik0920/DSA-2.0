#include <bits/stdc++.h>
#include <iostream>
using namespace std;

void printArr(vector<int> arr)
{
    for (auto i : arr)
    {
        cout << i << ' ';
    }
    cout << endl;
}
// 0 is for directed graph anf 1 is for undirected
class Graph
{
    int V, E;
    unordered_map<int, list<int>> adjlist;

    bool oBFS(unordered_map<int, bool> &visited, int src)
    {
        visited[src] = 1;
        queue<int> q;
        q.push(src);
        unordered_map<int, int> parent;
        parent[src] = -1;
        while (!q.empty())
        {
            int front = q.front();
            q.pop();

            for (auto i : adjlist[front])
            {
                if (visited[i] && i != parent[front])
                {
                    return 1;
                }
                else if (!visited[i])
                {
                    q.push(i);
                    visited[i] = 1;
                    parent[i] = front;
                }
            }
        }
        return 0;
    }

    bool oDFS(unordered_map<int, bool> &visited, int src, int parent)
    {
        visited[src] = 1;
        for (auto i : adjlist[src])
        {
            if (!visited[i])
            {
                bool ans = oDFS(visited, i, src);
                if (ans)
                {
                    return 1;
                }
            }
            else if (src != parent)
            {
                return 1;
            }
        }
        return 0;
    }

public:
    void AddEdge(int u, int v, bool type)
    {
        adjlist[u].push_back(v);
        if (type)
        {
            adjlist[v].push_back(u);
        }
    }

    Graph(int V, int E)
    {
        this->V = V;
        this->E = E;
    }

    void PrintGraph()
    {
        for (auto i : adjlist)
        {
            cout << i.first << ":";
            for (auto j : i.second)
            {
                cout << j << ',';
            }
            cout << endl;
        }
    }

    bool IsCycleBFS()
    {
        unordered_map<int, bool> visited;
        bool ans = 0;
        for (auto i : adjlist)
        {
            int u = i.first;
            if (!visited[u])
            {
                ans = oBFS(visited, u);
                if (ans)
                {
                    return 1;
                }
            }
        }
        return ans;
    }

    bool IsCycleDFS()
    {
        unordered_map<int, bool> visited;
        for (auto i : adjlist)
        {
            int u = i.first;
            if (!visited[u])
            {
                bool ans = oDFS(visited, u, -1);
                if (ans)
                {
                    return 1;
                }
            }
        }
        return 0;
    }
};
int main()
{
    int v, e;
    cout << "Enter vertices:";
    cin >> v;
    cout << "Enter edges:";
    cin >> e;
    Graph *g = new Graph(v, e);
    for (int i = 0; i < e; i++)
    {
        int u, v;
        cin >> u >> v;
        g->AddEdge(u, v, 1);
    }

    g->PrintGraph();
    cout << endl;
    if (g->IsCycleBFS())
    {
        cout << "Cycle is present" << endl;
    }
    else
    {
        cout << "Absent" << endl;
    }

    if (g->IsCycleDFS())
    {
        cout << "Cycle is present" << endl;
    }
    else
    {
        cout << "Absent" << endl;
    }
    return 0;
}