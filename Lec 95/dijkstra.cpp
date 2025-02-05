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

vector<int> dijkstra(int n, vector<vector<int>> edges, int src = 0)
{
    // Making adjlist
    unordered_map<int, list<pair<int, int>>> adjlist;
    for (auto i : edges)
    {
        int u = i[0], v = i[1], w = i[2];
        adjlist[u].push_back(make_pair(v, w));
        adjlist[v].push_back(make_pair(u, w));
    }

    vector<int> ans(n, INT_MAX);
    ans[src] = 0;
    set<pair<int, int>> s;
    s.insert(make_pair(0, src));
    // 1st element is distance while 2nd is node

    while (!s.empty())
    {
        pair<int, int> top = *s.begin();
        s.erase(s.begin());
        int currDistance = top.first;
        int currNode = top.second;

        for (auto i : adjlist[currNode])
        {
            int newDist = currDistance + i.second;
            if (newDist < ans[i.first])
            {
                auto record = s.find(make_pair(newDist, i.first));

                if (record != s.end())
                {
                    s.erase(record);
                }

                ans[i.first] = newDist;
                s.insert(make_pair(newDist, i.first));
            }
        }
    }

    return ans;
}
int main()
{
    int n = 4;
    vector<vector<int>> edges = {
        {1, 3, 2},
        {1, 0, 5},
        {1, 2, 9},
        {3, 2, 6},
        {2, 0, 8}};
    vector<int> arr = dijkstra(n, edges, 0);
    printArr(arr);
    return 0;
}