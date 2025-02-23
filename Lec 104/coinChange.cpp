#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int solve1(vector<int> arr, int target)
{
    if (target == 0)
    {
        return 0;
    }
    if (target < 0)
    {
        return INT_MAX;
    }
    int mini = INT_MAX;
    for (auto i : arr)
    {
        int ans = solve1(arr, target - i);
        if (ans != INT_MAX)
        {
            mini = min(ans + 1, mini);
        }
    }
    return mini;
}

int solve2(vector<int> arr, int target, vector<int> &dp)
{
    if (target == 0)
    {
        return 0;
    }
    if (target < 0)
    {
        return INT_MAX;
    }

    if (dp[target] != -1)
    {
        return dp[target];
    }

    int mini = INT_MAX;
    for (auto i : arr)
    {
        int ans = solve2(arr, target - i, dp);
        if (ans != INT_MAX)
        {
            mini = min(mini, ans);
        }
    }
    dp[target] = mini;
    return dp[target];
}

int getCoins(vector<int> arr, int target)
{
    int ans = solve1(arr, target);
    if (ans == INT_MAX)
    {
        return -1;
    }
    return ans;
}

int getCoins1(vector<int> arr, int target)
{
    vector<int> dp(target + 1, INT_MAX);
    int ans = solve2(arr, target, dp);
    return 0;
}

int getCoins2(vector<int> &arr, int target)
{
    vector<int> dp(target + 1, INT_MAX);
    dp[0] = 0;
    for (int i = 1; i <= target; i++)
    {
        for (int j = 0; j < arr.size(); j++)
        {
            if ((i - arr[j] >= 0) && (dp[i - arr[j]] != INT_MAX))
            {
                dp[i] = min(dp[i], 1 + dp[i - arr[j]]);
            }
        }
    }
    return dp[target] == INT_MAX ? -1 : dp[target];
}

int main()
{
    vector<int> arr = {1, 2, 5};
    int target = 11;
    cout << getCoins(arr, target) << endl;
    cout << getCoins(arr, target) << endl;
    cout << getCoins2(arr, target) << endl;
    return 0;
}