#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int solve1(vector<int> &cost, int n)
{
    // Bottom up Aproach
    vector<int> dp(n + 1, -1);
    dp[0] = cost[0];
    dp[1] = cost[1];

    for (int i = 2; i < n; i++)
    {
        dp[i] = cost[i] + min(dp[n - 1], dp[n - 2]);
    }

    return min(dp[n - 1], dp[n - 2]);
}

int solve2(vector<int> &cost, int n)
{
    // space optmized in bottom up
    int prev1 = cost[1];
    int prev2 = cost[0];

    for (int i = 2; i < n; i++)
    {
        int curr = cost[i] + min(prev1, prev2);
        prev2 = prev1;
        prev1 = curr;
    }

    return min(prev1, prev2);
}
int solve3(vector<int> &cost, int n, vector<int> &dp)
{
    // recusrion+memozition
    if (n <= 1)
    {
        return cost[n];
    }
    if (dp[n] != -1)
    {
        return dp[n];
    }

    dp[n] = cost[n] + min(solve3(cost, n - 1, dp), solve3(cost, n - 2, dp));

    return dp[n];
}

int main()
{
    vector<int> arr = {10, 15, 20};
    int n = arr.size();
    cout << solve1(arr, n) << endl;
    cout << solve2(arr, n) << endl;
    vector<int> dp(n + 1, -1);
    cout << min(solve3(arr, n - 1, dp), solve3(arr, n - 2, dp)) << endl;
    return 0;
}