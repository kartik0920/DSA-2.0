#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int minCost(vector<int> arr)
{
    priority_queue<int, vector<int>, greater<int>> pq;
    for (auto i : arr)
    {
        pq.push(i);
    }
    int cost = 0;
    while (pq.size() > 1)
    {
        int a = pq.top();
        pq.pop();
        int b = pq.top();
        pq.pop();
        int sum = a + b;
        cost += sum;
        pq.push(sum);
    }
    return cost;
}

int main()
{
    vector<int> arr = {4, 3, 2, 6};
    cout << minCost(arr) << endl;
    return 0;
}