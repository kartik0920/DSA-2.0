#include <bits/stdc++.h>
#include <iostream>
using namespace std;
void printArr(vector<int> arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << ' ';
    }
    cout << endl;
}
vector<int> min_of_subarrays(vector<int> arr, int n, int k)
{
    deque<int> mini;
    vector<int> ans;

    // first window
    for (int i = 0; i < k; i++)
    {
        while (!mini.empty() && arr[mini.back()] >= arr[i])
        {
            mini.pop_back();
        }
        mini.push_back(i);
    }

    ans.push_back(arr[mini.front()]);
    for (int i = k; i < n; i++)
    {
        while (!mini.empty() && i - mini.front() >= k)
        {
            mini.pop_front();
        }
        while (!mini.empty() && arr[mini.back()] >= arr[i])
        {
            mini.pop_back();
        }
        mini.push_back(i);
        ans.push_back(arr[mini.front()]);
    }
    return ans;
}
int main()
{
    vector<int> arr = {8, 5, 10, 7, 9, 4, 15, 12, 90, 13};
    int n = arr.size();
    int k = 10;
    arr = min_of_subarrays(arr, n, k);
    printArr(arr);
    return 0;
}