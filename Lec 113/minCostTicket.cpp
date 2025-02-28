#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int minCost(int n, vector<int> days, vector<int> cost, int index)
{
    if (index >= n)
    {
        return 0;
    }

    int option1 = cost[0] + minCost(n, days, cost, index + 1);

    int i;
    for (i = index; i < n && days[i] < days[index] + 7; i++)
    {
    }

    int option2 = cost[1] + minCost(n, days, cost, index + i);
    for (i = index; i < n && days[i] < days[index] + 30; i++)
    {
    }
    int option3 = cost[2] + minCost(n, days, cost, index + i);
    int ans = min(option1, min(option2, option3));
    return ans;
}

int minCost(int n, vector<int> days, vector<int> cost, int index, vector<int> &dp)
{
    if (index >= n)
    {
        return 0;
    }

    if (dp[index] != -1)
    {
        return dp[index];
    }

    int opt1 = cost[0] + minCost(n, days, cost, index + 1, dp);

    int i;
    for (i = index; i < n && days[i] < days[index] + 7; i++)
        ;

    int opt2 = cost[1] + minCost(n, days, cost, i, dp);

    for (i = index; i < n && days[i] < days[index] + 30; i++)
        ;

    int opt3 = cost[2] + minCost(n, days, cost, i, dp);

    dp[index] = min(opt1, min(opt2, opt3));
    return dp[index];
}

int minCostTabu(int n, vector<int> days, vector<int> cost)
{
    vector<int> dp(n + 1, INT_MAX);
    dp[n] = 0;

    for (int i = n - 1; i >= 0; i--)
    {
        int opt1 = cost[0] + dp[i + 1];

        int k;
        for (k = i; k < n && days[k] < days[i] + 7; k++)
            ;

        int opt2 = cost[1] + dp[i + k];

        for (k = i; k < n && days[k] < days[i] + 30; k++)
            ;

        int opt3 = cost[2] + dp[i + k];

        dp[i] = min(opt1, min(opt2, opt3));
    }
    return dp[0];
}

int main()
{
    vector<int> days = {2, 5};
    vector<int> cost = {1, 4, 25};
    int n = days.size();

    cout << minCost(n, days, cost, 0) << endl;

    // recusion + memo
    vector<int> dp(n + 1, -1);
    cout << minCost(n, days, cost, 0, dp) << endl;

    cout << minCostTabu(n, days, cost) << endl;

    return 0;
}