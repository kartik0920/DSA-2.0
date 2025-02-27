#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int solveRec(vector<int> arr, int n, int x)
{
    if (x == 0)
    {
        return 1;
    }
    if (x < 0)
    {
        return 0;
    }

    int ans = 0;
    for (auto i : arr)
    {
        ans += solveRec(arr, n, x - i);
    }
    return ans;
}

int solveMemo(vector<int> arr, int n, int x, vector<int> &dp)
{
    if (x == 0)
    {
        return 1;
    }
    if (x < 0)
    {
        return 0;
    }

    if (dp[x] != -1)
    {
        return dp[x];
    }

    int ans = 0;
    for (auto i : arr)
    {
        ans += solveMemo(arr, n, x - i, dp);
    }

    dp[x] = ans;
    return dp[x];
}

int solveTabu(vector<int> arr, int n, int x)
{
    vector<int> dp(x + 1, 0);
    dp[0] = 1;

    for (int i = 1; i <= x; i++)
    {
        int ans = 0;
        for (auto ele : arr)
        {
            if (i - ele >= 0)
            {
                dp[i] += dp[i - ele];
            }
        }
        // dp[i] = ans;
    }
    return dp[x];
}

int main()
{
    vector<int> arr = {1, 2};
    int n = arr.size();
    int target = 5;

    // recursion
    cout << solveRec(arr, n, target) << endl;

    // recusiron + memoization
    vector<int> dp(target + 1, -1);
    cout << solveMemo(arr, n, target, dp) << endl;

    // tabulation
    cout << solveTabu(arr, n, target);
    return 0;
}