#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int kthLargestSum(vector<int> arr, int k)
{
    int n = arr.size();
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += arr[j];
            if (pq.size() < k)
            {
                pq.push(sum);
            }
            else
            {
                if (sum > pq.top())
                {
                    pq.pop();
                    pq.push(sum);
                }
            }
        }
    }
    return pq.top();
}

int main()
{
    vector<int> arr = {10, -10, 20, -40};
    int k = 6;
    cout << kthLargestSum(arr, k) << endl;
    return 0;
}