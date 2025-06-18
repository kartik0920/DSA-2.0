#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int solve(vector<int> &arr, int index, int time)
{
    if (index == arr.size())
    {
        return 0;
    }

    int incl = time * arr[index] + solve(arr, index + 1, time + 1);
    int excl = solve(arr, index + 1, time);

    return max(incl, excl);
}

int solveMem(vector<int> &arr, int index, int time, vector<vector<int>> &dp)
{
    if (index == arr.size())
    {
        return 0;
    }
    if (dp[index][time] != -1)
    {
        return dp[index][time];
    }

    int incl = (time * arr[index]) + solveMem(arr, index + 1, time + 1, dp);
    int excl = solveMem(arr, index + 1, time, dp);

    return dp[index][time] = max(incl, excl);
}

int solveTab(vector<int> &arr)
{
    int n = arr.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

    for (int i = n - 1; i >= 0; i--)
    {
        for (int t = i; t >= 0; t--)
        {
            int incl = arr[i] * t + dp[i + 1][t + 1];
            int excl = dp[i + 1][t];

            dp[i][t] = max(incl, excl);
        }
    }
    return dp[0][0];
}

int spaceOpt(vector<int> &arr)
{
    int n = arr.size();
    vector<int> curr(n + 1, 0);
    vector<int> next(n + 1, 0);

    for (int i = n - 1; i >= 0; i--)
    {
        for (int t = i; t >= 0; t--)
        {
            int incl = t * arr[i] + next[t + 1];
            int excl = next[t];

            curr[t] = max(incl, excl);
        }
        next = curr;
    }
    return next[0];
}

int main()
{
    vector<int> arr = {-1, -8, 0, 5, -9};
    sort(arr.begin(), arr.end());

    cout << solve(arr, 0, 0) << endl;

    int n = arr.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
    cout << solveMem(arr, 0, 0, dp) << endl;

    cout << solveTab(arr) << endl;

    cout << spaceOpt(arr) << endl;

    return 0;
}