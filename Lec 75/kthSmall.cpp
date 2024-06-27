#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int klarge(vector<int> arr, int k)
{
    int n = arr.size();
    if (k > n)
    {
        return -1;
    }
    priority_queue<int> pq;
    for (int i = 0; i < k; i++)
    {
        pq.push(arr[i]);
    }

    for (int i = k; i < n; i++)
    {
        if (arr[i] < pq.top())
        {
            pq.pop();
            pq.push(arr[i]);
        }
    }

    return pq.top();
}
int main()
{
    vector<int> arr = {5, 4, 3, 2, 1};
    int k = 2;
    cout << klarge(arr, k) << endl;
    return 0;
}