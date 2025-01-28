#include <bits/stdc++.h>
#include <iostream>
using namespace std;

pair<int, int> solve(vector<int> arr, int k)
{
    if (k > arr.size())
    {
        return {-1, -1};
    }
    priority_queue<int> pq1;
    priority_queue<int, vector<int>, greater<int>> pq2;

    for (auto i : arr)
    {
        pq1.push(i);
        pq2.push(i);
    }

    while (k > 1)
    {
        pq1.pop();
        pq2.pop();
        k--;
    }
    return make_pair(pq1.top(), pq2.top());
}

int main()
{
    vector<int> arr = {1, 5, 3, 2, 4};
    int k = 1;
    pair<int, int> ans = solve(arr, k);
    cout << ans.first << " " << ans.second << endl;
    return 0;
}