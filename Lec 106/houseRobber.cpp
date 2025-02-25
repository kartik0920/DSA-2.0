#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int solveSpace(vector<int> arr)
{
    int prev2 = 0;
    int prev1 = arr[0];
    int n = arr.size();
    for (int i = 1; i < n; i++)
    {
        int incl = prev2 + arr[i];
        int excl = prev1;
        int ans = max(incl, excl);

        prev2 = prev1;
        prev1 = ans;
    }
    return prev1;
}

int solve(vector<int> arr)
{
    vector<int> first, second;
    int n = arr.size();
    if (n == 1)
    {
        return arr[0];
    }
    for (int i = 0; i < n; i++)
    {
        // include first

        if (i != n - 1)
        {
            first.push_back(arr[i]);
        }
        if (i != 0)
        {
            second.push_back(arr[i]);
        }
    }

    return max(solveSpace(first), solveSpace(second));
}

int main()
{
    vector<int> arr = {1};

    cout << solve(arr) << endl;
    return 0;
}