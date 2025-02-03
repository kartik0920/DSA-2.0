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

vector<int> getToposort(int n, vector<vector<int>> edges)
{
    vector<int> ans;
    queue<int> q;
    unordered_map<int, list<int>> adjlist;
    for (auto i : edges)
    {
        int u = i[0], v = i[1];
        adjlist[u].push_back(v);
    }

    vector<int> inOrder(n + 1);
    for (auto i : adjlist)
    {
        for (auto j : i.second)
        {
            inOrder[j]++;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (inOrder[i] == 0)
        {
            q.push(i);
        }
    }

    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        ans.push_back(node);

        for (auto i : adjlist[node])
        {
            inOrder[i]--;
            if (inOrder[i] == 0)
            {
                q.push(i);
            }
        }
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