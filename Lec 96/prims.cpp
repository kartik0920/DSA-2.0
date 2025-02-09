#include <bits/stdc++.h>
#include <iostream>
using namespace std;

void print(vector<pair<pair<int, int>, int>> ans)
{
    for (auto i : ans)
    {
        cout << '(' << i.first.first << ',' << i.first.second << ") -> " << i.second << endl;
    }
    cout << endl;
}

vector<pair<pair<int, int>, int>> solve(int n, int m, vector<pair<pair<int, int>, int>> edges)
{
    unordered_map<int, list<pair<int, int>>> adjlist;
    for (auto i : edges)
    {
        int u = i.first.first, v = i.first.second, w = i.second;
        adjlist[u].push_back(make_pair(v, w));
        adjlist[v].push_back(make_pair(u, w));
    }

    vector<int> key(n, INT_MAX);
    vector<int> parent(n, -1);
    vector<bool> mst(n, 0);
    // let src=1
    parent[0] = -1;
    priority_queue<int, vector<int>, greater<int>> pq;
    pq.push(0);
    mst[0] = 1;
    key[0] = 0;

    for (int i = 1; i <= n; i++)
    {
        int min = pq.top();
        pq.pop();
        for (auto it : adjlist[min])
        {
            int v = it.first, w = it.second;
            if (!mst[v] && w < key[v])
            {
                pq.push(v);
                parent[v] = min;
                mst[v] = 1;
                key[v] = w;
            }
        }
    }

    vector<pair<pair<int, int>, int>> ans;

    for (int i = 1; i < n; i++)
    {
        ans.push_back({{parent[i], i}, key[i]});
    }

    return ans;
}
int main()
{
    int n = 5;
    int m = 6;
    vector<pair<pair<int, int>, int>> edges = {
        {{0, 3}, 6},
        {{0, 1}, 2},
        {{1, 3}, 8},
        {{1, 4}, 5},
        {{1, 2}, 3},
        {{2, 4}, 7}};

    vector<pair<pair<int, int>, int>> ans = solve(n, m, edges);

    print(ans);
    return 0;
}