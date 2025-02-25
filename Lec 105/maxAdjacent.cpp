#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int solveRec(vector<int> arr, int n)
{
    if (n < 0)
    {
        return 0;
    }
    if (n == 0)
    {
        return arr[0];
    }

    int include = arr[n] + solveRec(arr, n - 2);
    int exclude = 0 + solveRec(arr, n - 1);

    return max(include, exclude);
}

int solveMem(vector<int> arr, int n, vector<int> &dp)
{
    if (n == 0)
    {
        return arr[0];
    }
    if (n < 0)
    {
        return 0;
    }

    if (dp[n] != -1)
    {
        return dp[n];
    }
    int include = arr[n] + solveMem(arr, n - 2, dp);
    int exclude = solveMem(arr, n - 1, dp);

    dp[n] = max(include, exclude);
    return dp[n];
}

int solveTab(vector<int> arr)
{
    int n = arr.size();
    vector<int> dp(n, 0);
    dp[0] = arr[0];

    for (int i = 1; i < n; i++)
    {
        int incl = 0;
        if (i - 2 >= 0)
            incl = arr[i] + dp[i - 2];
        int excl = dp[i - 1];

        dp[i] = max(incl, excl);
    }
    return dp[n - 1];
}

int solveSpaceOptimized(vector<int> arr)
{
    int prev2 = 0;
    int prev1 = arr[0];
    int n = arr.size();
    for (int i = 1; i < n; i++)
    {
        int incl = arr[i] + prev2;
        int excl = prev1;
        int ans = max(incl, excl);

        prev2 = prev1;
        prev1 = ans;
    }
    return prev1;
}

int main()
{
    vector<int> arr = {9, 9, 8, 2};
    int n = arr.size();
    vector<int> dpArr(n + 1, -1);
    cout << solveRec(arr, n - 1) << endl;
    cout << solveMem(arr, n - 1, dpArr) << endl;
    cout << solveTab(arr) << endl;
    cout << solveSpaceOptimized(arr) << endl;
    return 0;
}