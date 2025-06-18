#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int minTriangle(vector<int> &arr, int i, int j)
{
    if (i + 1 == j)
    {
        return 0;
    }

    int ans = INT_MAX;
    for (int k = i + 1; k < j; k++)
    {
        ans = min(ans,
                  arr[i] * arr[k] * arr[j] + minTriangle(arr, i, k) + minTriangle(arr, k, j));
    }
    return ans;
}

int minTriangleMem(vector<int> &arr, int i, int j, vector<vector<int>> &dp)
{
    if (i + 1 == j)
    {
        return 0;
    }
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    int ans = INT_MAX;
    for (int k = i + 1; k < j; k++)
    {
        ans = min(ans,
                  arr[i] * arr[k] * arr[j] + minTriangle(arr, i, k) + minTriangle(arr, k, j));
    }
    return dp[i][j] = ans;
}

int main()
{
    vector<int> arr = {5, 3, 7, 4};
    int n = arr.size();
    int i = 0, j = arr.size() - 1;
    cout << minTriangle(arr, i, j) << endl;

    vector<vector<int>> dp(n, vector<int>(n, -1));

    cout << minTriangleMem(arr, i, j, dp) << endl;

    return 0;
}