#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int solve(vector<int> &arr, int index, int n, int &mini)
{

    if (index >= n)
    {
        return 0;
    }

    int jumps = arr[index] + index;

    int ans = INT_MAX;
    for (int i = index; i < jumps; i++)
    {
        int temp = solve(arr, i + 1, n, mini);
        ans = min(ans, temp + 1);
    }
    return ans;
}
int minJumps(vector<int> &arr)
{
    int mini = INT_MAX;
    int n = arr.size();
    return solve(arr, 0, n, mini);
}
int main()
{
    vector<int> arr = {1, 2, 3};
    cout << minJumps(arr);
    return 0;
}