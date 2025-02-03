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

bool isCycle(int n, vector<vector<int>> edges)
{
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
    queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        if (inOrder[i] == 0)
        {
            q.push(i);
        }
    }
    int cnt = 0;

    while (!q.empty())
    {
        int temp = q.front();
        q.pop();
        cnt++;

        for (auto i : adjlist[temp])
        {
            inOrder[i]--;
            if (inOrder[i] == 0)
            {
                q.push(i);
            }
        }
    }
    if (cnt == n)
    {
        return 0;
    }
    return 1;
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

    cout << isCycle(n, edges) << endl;
    return 0;
}