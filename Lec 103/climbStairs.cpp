#include <bits/stdc++.h>
#include <iostream>
#define MOD 100000007
using namespace std;

int solve(int src, int dest, vector<int> &arr)
{

    if (src == dest)
        return 1;
    if (src > dest)
    {
        return 0;
    }
    if (arr[src] != -1)
    {
        return arr[src];
    }
    arr[src] = solve(src + 1, dest, arr) + solve(src + 2, dest, arr) % MOD;
    return arr[src];
}

int main()
{
    int n = 5;
    // op=3

    vector<int> arr(n + 1, -1);
    cout << solve(0, n, arr) << endl;

    return 0;
}