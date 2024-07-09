#include <bits/stdc++.h>
#include <iostream>
using namespace std;

bool IsSafe(vector<vector<bool>> arr, int n, vector<vector<bool>> visited, int x, int y)
{
    if ((x >= 0 && x < n) && (y >= 0 && y < n) && visited[x][y] == 0 && arr[x][y] == 1)
    {
        return 1;
    }
    return 0;
}

void solve(vector<vector<bool>> arr, int n, vector<string> &ans, string path, vector<vector<bool>> visited, int x, int y)
{
    if (x == n - 1 && y == n - 1)
    {
        ans.push_back(path);
        return;
    }

    // down
    if (IsSafe(arr, n, visited, x + 1, y))
    {
        visited[x][y] = 1;
        solve(arr, n, ans, path + 'D', visited, x + 1, y);
    }

    // left
    if (IsSafe(arr, n, visited, x, y - 1))
    {
        visited[x][y] = 1;
        solve(arr, n, ans, path + 'L', visited, x, y - 1);
    }

    // right
    if (IsSafe(arr, n, visited, x, y + 1))
    {
        visited[x][y] = 1;
        solve(arr, n, ans, path + 'R', visited, x, y + 1);
    }

    // up
    if (IsSafe(arr, n, visited, x - 1, y))
    {
        visited[x][y] = 1;
        solve(arr, n, ans, path + 'U', visited, x - 1, y);
    }

    visited[x][y] = 0;
}
vector<string> RatinMaze(vector<vector<bool>> arr, int n)
{
    if (arr[0][0] == 0)
    {
        return {""};
    }
    vector<vector<bool>> visited(n, vector<bool>(n, 0));
    vector<string> ans;
    string path = "";
    int x = 0, y = 0;
    solve(arr, n, ans, path, visited, x, y);
    return ans;
}
int main()
{
    vector<vector<bool>> arr = {
        {1, 1, 0, 0},
        {0, 1, 1, 1},
        {1, 1, 0, 1},
        {1, 1, 1, 1}};
    int n = arr.size();
    vector<string> ans = RatinMaze(arr, n);
    for (auto i : ans)
    {
        cout << i << ' ';
    }
    cout << "Done" << endl;
    return 0;
}