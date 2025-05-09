#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int main()
{
    int n = 3, e = 3;
    vector<vector<int>> edges = {
        {0, 1},
        {1, 2},
        {2, 0}};

    vector<vector<bool>> adjMat(n, vector<bool>(n, 0));
    for (auto i : edges)
    {
        int u = i[0], v = i[1];
        adjMat[u][v] = 1;
    }
    a for (auto i : adjMat)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}