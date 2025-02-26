#include <bits/stdc++.h>
#include <iostream>
using namespace std;

#define MOD 1000000007

int solve(int n)
{
    if (n == 1)
    {
        return 0;
    }
    if (n == 2)
    {
        return 1;
    }

    int ans = ((n - 1) % MOD) * (((solve(n - 1)) % MOD + (solve(n - 2)) % MOD) % MOD);
    return ans;
}

int solveMem(int n, vector<int> &dp)
{
    if (n == 1)
    {
        return 0;
    }
    if (n == 2)
    {
        return 1;
    }
    if (dp[n] != -1)
    {
        return dp[n];
    }

    int ans = ((n - 1) % MOD) * ((solveMem(n - 1, dp) % MOD) + (solveMem(n - 2, dp) % MOD) % MOD);
    return ans;
}

int solveTab(int n)
{
    vector<int> dp(n + 1, 0);
    dp[1] = 0;
    dp[2] = 1;

    for (int i = 3; i <= n; i++)
    {
        dp[i] = (i - 1) % MOD * (dp[i - 1] % MOD + dp[i - 2] % MOD) % MOD;
    }
    return dp[n];
}

int solveSpace(int n)
{
    int prev1 = 0;
    int prev2 = 1;

    for (int i = 3; i <= n; i++)
    {
        int ans = (i - 1) % MOD * (prev1 % MOD + prev2 % MOD) % MOD;
        prev1 = prev2;
        prev2 = ans;
    }
    return prev2;
}

int main()
{
    int n = 3;
    // solve by recursion
    cout << solve(n) << endl;

    // solve by recusrion+memo
    vector<int> dp(n + 1, -1);
    cout << solveMem(n, dp) << endl;

    // solve by tabulation
    cout << solveTab(n) << endl;

    // solve by space optimization
    cout << solveSpace(n) << endl;
    return 0;
}