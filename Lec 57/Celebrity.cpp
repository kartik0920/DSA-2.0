#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int celebrity1(vector<vector<int>> &M, int n)
{

    for (int i = 0; i < n; i++)
    {
        int zerocnt = 0, onecnt = 0;
        for (int j = 0; j < n; j++)
        {
            if (M[i][j] == 0)
            {
                zerocnt++;
            }
        }
        for (int j = 0; j < n; j++)
        {
            if (M[j][i] == 1)
            {
                onecnt++;
            }
        }
        if (onecnt == n - 1 && zerocnt == n)
        {
            return i;
        }
    }
    return -1;
}
int celebrity2(vector<vector<int>> &M, int n)
{
    // step 1 create stack
    stack<int> s;
    for (int i = 0; i < n; i++)
    {
        s.push(i);
    }

    // step 2 elimating all other elements
    while (s.size() > 1)
    {
        int a = s.top();
        s.pop();
        int b = s.top();
        s.pop();
        if (M[a][b] == 1)
        {
            s.push(b);
        }
        else
        {
            s.push(a);
        }
    }
    int ans = s.top();
    // checking if row is NULL
    for (int i = 0; i < n; i++)
    {
        if (M[ans][i] == 1)
        {
            return -1;
        }
    }
    // checking for column
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (M[i][ans] == 1)
        {
            cnt++;
        }
    }
    if (cnt != n - 1)
    {
        return -1;
    }
    // return ans
    return ans;
}

int main()
{
    vector<vector<int>> M = {{0, 1, 0},
                             {0, 0, 0},
                             {0, 1, 0}};
    cout << celebrity2(M, 3) << endl;
    cout << celebrity1(M, 3) << endl;
    return 0;
}