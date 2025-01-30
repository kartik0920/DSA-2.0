#include <bits/stdc++.h>
#include <iostream>
using namespace std;

bool isSafe(int x, int y, int n, vector<vector<bool>> visited, vector<vector<bool>> arr)
{
    if ((x >= 0 && x < n) && (y >= 0 && y < n) && (!visited[x][y]) && (arr[x][y]))
    {
        return 1;
    }
    return 0;
}

void solve(vector<vector<bool>> &arr, int n, vector<string> &ans, string path, vector<vector<bool>> &visited, int x, int y)
{
    if (x == n - 1 && y == n - 1)
    {
        ans.push_back(path);
        return;
    }
    // D L R U
    visited[x][y] = 1;
    if (isSafe(x + 1, y, n, visited, arr))
    {
        solve(arr, n, ans, path + 'D', visited, x + 1, y);
    }
    if (isSafe(x, y - 1, n, visited, arr))
    {
        solve(arr, n, ans, path + 'L', visited, x, y - 1);
    }
    if (isSafe(x, y + 1, n, visited, arr))
    {
        solve(arr, n, ans, path + 'R', visited, x, y + 1);
    }
    if (isSafe(x - 1, y, n, visited, arr))
    {
        solve(arr, n, ans, path + 'U', visited, x - 1, y);
    }
    visited[x][y] = 0;
}

vector<string> ratinmaze(vector<vector<bool>> arr, int n)
{

    if (!arr[0][0])
    {
        return {"-1"};
    }
    vector<string> ans;
    string path = "";
    vector<vector<bool>> visited(n, vector<bool>(n, 0));
    solve(arr, n, ans, path, visited, 0, 0);
    return ans;
}

int main()
{
    vector<vector<bool>> arr = {
        {1, 0, 0, 0},
        {1, 1, 0, 0},
        {1, 1, 0, 0},
        {0, 1, 1, 1}};
    int n = arr.size();
    vector<string> ans = ratinmaze(arr, n);
    for (auto i : ans)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}