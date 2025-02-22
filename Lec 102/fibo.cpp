#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int fibo(int n, vector<int> &arr)
{
    if (n <= 1)
    {
        return n;
    }
    if (arr[n] != -1)
    {
        return arr[n];
    }
    arr[n] = fibo(n - 1, arr) + fibo(n - 2, arr);
    return arr[n];
}

int main()
{
    int n = 5;

    vector<int> dparr1(n + 1, -1), dparr2(n + 1, -1);
    // top down =recusrion+memoziation
    cout << fibo(n, dparr1) << endl;

    // bottom up : tabular form
    dparr2[0] = 0;
    dparr2[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        dparr2[i] = dparr2[i - 1] + dparr2[i - 2];
    }
    cout << dparr2[n] << endl;

    return 0;
}