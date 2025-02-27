#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int getMin(int n, vector<int> &dp)
{
    if (n == 0)
    {
        return 0;
    }

    if (dp[n] != -1)
    {
        return dp[n];
    }

    int ans = n;
    for (int i = 1; i * i <= n; i++)
    {
        ans = min(ans, 1 + getMin(n - i * i, dp));
    }
    dp[n] = ans;
    return dp[n];
}

int solveTabu(int n)
{
    vector<int> dp(n + 1, INT_MAX);
    dp[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j * j <= n; j++)
        {
            int temp = j * j;
            if (i - temp >= 0)
                dp[i] = min(dp[i], 1 + dp[i - temp]);
        }
    }

    return dp[n];
}

int main()
{
    int n = 100;
    vector<int> dp(n + 1, -1);

    // recusrion + memoization
    cout << getMin(n, dp) << endl;

    // tabulation
    cout << solveTabu(n) << endl;
    return 0;
}