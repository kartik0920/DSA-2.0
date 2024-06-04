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
    deque<int> maxi;
    vector<int> ans;

    // first window
    for (int i = 0; i < k; i++)
    {
        while (!maxi.empty() && arr[maxi.back()] <= arr[i])
        {
            maxi.pop_back();
        }
        maxi.push_back(i);
    }
    ans.push_back(arr[maxi.front()]);
    for (int i = k; i < n; i++)
    {
        while (!maxi.empty() && i - maxi.front() >= k)
        {
            maxi.pop_front();
        }
        while (!maxi.empty() && arr[maxi.back()] <= arr[i])
        {
            maxi.pop_back();
        }
        maxi.push_back(i);
        ans.push_back(arr[maxi.front()]);
    }
    return ans;
}
int main()
{
    vector<int> arr = {8, 5, 10, 7, 9, 4, 15, 12, 90, 13};
    int n = arr.size();
    int k = 1;
    arr = min_of_subarrays(arr, n, k);
    printArr(arr);
    return 0;
}