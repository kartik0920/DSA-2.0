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

void dfs(int node, unordered_map<int, bool> &visited, stack<int> &st, unordered_map<int, list<pair<int, int>>> adjlist)
{
    visited[node] = 1;
    for (auto i : adjlist[node])
    {
        if (!visited[i.first])
        {
            dfs(i.first, visited, st, adjlist);
        }
    }
    st.push(node);
}

vector<int> getPath(int n, vector<vector<int>> edges, int src)
{
    unordered_map<int, list<pair<int, int>>> adjlist;

    for (auto i : edges)
    {
        int u = i[0], v = i[1], w = i[2];
        pair<int, int> temp = make_pair(v, w);
        adjlist[u].push_back(temp);
    }
    vector<int> ans(n, INT_MAX);
    unordered_map<int, bool> visited;
    stack<int> st;

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            dfs(i, visited, st, adjlist);
        }
    }
    ans[src] = 0;

    while (!st.empty())
    {
        int top = st.top();
        st.pop();

        if (ans[top] != INT_MAX)
        {
            for (auto i : adjlist[top])
            {
                int newSum = i.second + ans[top];
                if (newSum < ans[i.first])
                {
                    ans[i.first] = newSum;
                }
            }
        }
    }

    return ans;
}

int main()
{
    int n = 6;
    vector<vector<int>> edges = {
        {0, 1, 5},
        {0, 2, 3},
        {1, 2, 2},
        {1, 3, 6},
        {2, 3, 7},
        {2, 4, 4},
        {2, 5, 2},
        {3, 4, -1},
        {4, 5, -2}};

    vector<int> shortesPath = getPath(n, edges, 1);
    printArr(shortesPath);
    return 0;
}