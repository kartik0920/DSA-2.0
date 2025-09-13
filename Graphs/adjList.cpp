#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int main()
{
    int n = 5, e = 6;
    vector<vector<int>> edges = {
        {0, 1},
        {1, 3},
        {1, 2},
        {3, 2},
        {0, 4},
        {4, 3}};

    unordered_map<int, list<int>> adjlist;
    for (auto i : edges)
    {
        int u = i[0], v = i[1];
        adjlist[u].push_back(v);
        adjlist[v].push_back(u);
    }

    for (auto i : adjlist)
    {
        cout << i.first << " : ";
        for (auto j : i.second)
        {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}