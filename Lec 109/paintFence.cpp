#include <bits/stdc++.h>
#include <iostream>
using namespace std;

#define MOD 1000000007

int solve(int n, int k)
{
    if (n == 1)
    {
        return k;
    }
    if (n == 2)
    {
        return k + (k * (k - 1));
    }

    int ans = (solve(n - 1, k) * (k - 1)) + (solve(n - 2, k) * (k - 1));
    return ans;
}

int solveMem(int n, int k, vector<int> &dp)
{
    if (n == 1)
    {
        return k;
    }
    if (n == 2)
    {
        return k + (k * (k - 1));
    }
    if (dp[n] != -1)
    {
        return dp[n];
    }

    dp[n] = (solveMem(n - 1, k, dp) * (k - 1)) + (solveMem(n - 2, k, dp) * (k - 1));
    return dp[n];
}

int solveTab(int n, int k)
{
    vector<int> dp(n + 1, 0);
    dp[1] = k;
    dp[2] = k + (k * (k - 1));

    for (int i = 3; i <= n; i++)
    {
        dp[i] = (dp[i - 1] * (k - 1)) + (dp[i - 2] * (k - 1));
    }
    return dp[n];
}

int solveSpace(int n, int k)
{
    int prev1 = k;
    int prev2 = k + (k * (k - 1));

    for (int i = 3; i <= n; i++)
    {
        int ans = (prev1 * (k - 1)) + (prev2 * (k - 1));
        prev1 = prev2;
        prev2 = ans;
    }
    return prev2;
}

int main()
{
    int n = 3;
    int k = 2;
    // solve by recursion
    cout << solve(n, k) << endl;

    // solve by recusrion+memo
    vector<int> dp(n + 1, -1);
    cout << solveMem(n, k, dp) << endl;

    // solve by tabulation
    cout << solveTab(n, k) << endl;

    // solve by space optimization
    cout << solveSpace(n, k) << endl;
    return 0;
}