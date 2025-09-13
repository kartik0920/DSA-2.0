#include <bits/stdc++.h>
#include <iostream>
using namespace std;

vector<int> shortest(int n, vector<vector<int>> edges, int src)
{

    // Step 1 Created a adjancey list
    unordered_map<int, list<pair<int, int>>> adj;
    for (auto i : edges)
    {
        int u = i[0], v = i[1], w = i[2];
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    // this vector contains all distance to track
    vector<int> dist(n, INT_MAX);

    // set is used for gettting node with smallest distance  <pair<int,int>> === pair <dist , node>
    set<pair<int, int>> st;
    dist[src] = 0;

    // inserting first node with distance from source is 0
    st.insert({0, src});

    // operting while set != empty
    while (!st.empty())
    {

        // getting samleest distnace from availble set
        auto top = *st.begin();

        // getting node and distance
        int currDist = top.first, currNode = top.second;

        // Poping the entity
        st.erase(st.begin());

        // traversing all neighbours node
        for (auto i : adj[currNode])
        {

            // calculating new distance
            int new_dist = i.second + currDist;

            // if new distance is small upldating otherwise ignoring it
            if (dist[i.first] > new_dist)
            {
                // used for deleting record for previous node value
                auto record = st.find({dist[i.first], i.first});

                if (record != st.end())
                {
                    st.erase(record);
                }

                // updating dist array with smallest distance
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

    vector<int> arr = shortest(n, edges, 0);

    for (auto i : arr)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}