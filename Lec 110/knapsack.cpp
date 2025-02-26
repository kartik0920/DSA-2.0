#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int solveRecursion(vector<int> wt, vector<int> val, int index, int capacity)
{
    // step 1 base condition
    if (index == 0)
    {
        if (wt[0] <= capacity)
        {
            return val[0];
        }
        else
        {
            return 0;
        }
    }

    // step 2 checking include and exclude
    int include = 0;
    if (wt[index] <= capacity)
    {
        include = val[index] + solveRecursion(wt, val, index - 1, capacity - wt[index]);
    }
    int exclude = solveRecursion(wt, val, index - 1, capacity);

    int ans = max(include, exclude);
    return ans;
}

int solveMemo(vector<int> wt, vector<int> val, int index, int capacity, vector<vector<int>> &dp)
{
    if (index == 0)
    {
        if (wt[0] <= capacity)
        {
            return val[0];
        }
        else
        {
            return 0;
        }
    }
    if (dp[index][capacity] != -1)
    {
        return dp[index][capacity];
    }

    int include = 0;
    if (wt[index] <= capacity)
        include = val[index] + solveMemo(wt, val, index - 1, capacity - wt[index], dp);
    int exclude = solveMemo(wt, val, index - 1, capacity, dp);

    dp[index][capacity] = max(include, exclude);
    return dp[index][capacity];
}

int main()
{
    vector<int> wt = {1, 2, 4, 5};
    vector<int> value = {5, 4, 8, 6};
    int n = wt.size();
    int maxWt = 5;
    // step 1 solve by recursion
    cout << solveRecursion(wt, value, n - 1, maxWt) << endl;

    // step 2 solve by recursion + memoization
    vector<vector<int>> dp(n, vector<int>(maxWt + 1, -1));
    cout << solveMemo(wt, value, n - 1, maxWt, dp) << endl;

    return 0;
}