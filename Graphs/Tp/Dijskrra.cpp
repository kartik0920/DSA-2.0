#include <bits/stdc++.h>
#include <iostream>
using namespace std;

vector<int> shortest(int n, vector<vector<int>> edges, int src = 0)
{
    // Making adj list
    unordered_map<int, list<pair<int, int>>> adj;
    for (auto i : edges)
    {
        int u = i[0], v = i[1], w = i[2];
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    vector<int> dist(n, INT_MAX);
    set<pair<int, int>> st;

    st.insert({0, src});
    dist[src] = 0;
    while (!st.empty())
    {
        auto top = *st.begin();
        int currNode = top.second, currDist = top.first;
        ;
        st.erase(*st.begin());

        for (auto i : adj[currNode])
        {
            int new_dist = currDist + i.second;
            if (dist[i.first] > new_dist)
            {
                auto record = st.find({dist[i.first], i.first});
                if (record != st.end())
                {
                    st.erase({dist[i.first], i.first});
                }
                dist[i.first] = new_dist;
                st.insert({new_dist, i.first});
            }
        }
    }
    return dist;
}
int main()
{
    vector<vector<int>> edges = {
        {1, 0, 5},
        {1, 2, 9},
        {1, 3, 2},
        {3, 2, 6},
        {0, 2, 8}};
    int n = 4;

    vector<int> arr = shortest(n, edges);

    for (auto i : arr)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}