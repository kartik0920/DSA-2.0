#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int solve(int src, int dest)
{
    if (src == dest)
        return 1;
    if (src > dest)
    {
        return 0;
    }
    return solve(src + 1, dest) + solve(src + 2, dest);
}

int main()
{
    int n = 2;
    // op=3
    int cnt = 0;
    cout << solve(0, n) << endl;

    return 0;
}