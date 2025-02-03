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

void dfsCheck(int node, unordered_map<int, list<int>> adjlist, unordered_map<int, bool> &visited, stack<int> &st)
{
    visited[node] = 1;
    for (auto i : adjlist[node])
    {
        if (!visited[i])
        {
            dfsCheck(i, adjlist, visited, st);
        }
    }
    st.push(node);
}

vector<int> getToposort(int n, vector<vector<int>> edges)
{
    unordered_map<int, list<int>> adjlist;
    for (auto i : edges)
    {
        int u = i[0], v = i[1];
        adjlist[u].push_back(v);
    }
    unordered_map<int, bool> visited;
    stack<int> st;
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            dfsCheck(i, adjlist, visited, st);
        }
    }
    vector<int> ans;
    while (!st.empty())
    {
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
}

int main()
{
    int n = 6;
    vector<vector<int>> edges = {
        {1, 2},
        {2, 4},
        {4, 5},
        {4, 6},
        {5, 6},
        {1, 3},
        {3, 4}};

    vector<int> topoSort = getToposort(n, edges);
    printArr(topoSort);
    return 0;
}