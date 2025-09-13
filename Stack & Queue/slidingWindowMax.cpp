#include <bits/stdc++.h>
#include <iostream>
using namespace std;
vector<int> solve(vector<int> arr)
{
    vector<int> res;
    deque<int> dq;

    for (int i = 0; i < k; ++i)
    {
        while (!dq.empty() && arr[i] >= arr[dq.back()])
        {
            dq.pop_back();
        }
        dq.push_back(i);
    }
    for (int i = k; i < arr.size(); ++i)
    {
        res.push_back(arr[dq.front()]);
        while (!dq.empty() && dq.front() <= i - k)
        {
            dq.pop_front();
        }
        while (!dq.empty() && arr[i] >= arr[dq.back()])
        {
            dq.pop_back();
        }
        dq.push_back(i);
    }
    res.push_back(arr[dq.front()]);

    return res;
}
int main()
{

    return 0;
}