#include <iostream>
#include <vector>
using namespace std;

void printArr(vector<string> arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << ' ';
    }
    cout << endl;
}

bool Allowed(int x, int y, vector<vector<int>> &m, vector<vector<int>> visited, int n)
{
    if ((x >= 0 && x < n) && (y >= 0 && y < n) && (visited[x][y] == 0) && (m[x][y] == 1))
    {
        return 1;
    }
    return 0;
}
void solve(vector<vector<int>> &m, int n, vector<string> &ans, vector<vector<int>> visited, int x, int y, string path)
{
    if (x == n - 1 && y == n - 1)
    {
        ans.push_back(path);
        return;
    }

    visited[x][y] = 1;

    // down
    int newx = x + 1;
    int newy = y;
    if (Allowed(newx, newy, m, visited, n))
    {
        path.push_back('D');
        solve(m, n, ans, visited, newx, newy, path);
        path.pop_back();
    }

    // up
    newx = x - 1;
    newy = y;
    if (Allowed(newx, newy, m, visited, n))
    {
        path.push_back('U');
        solve(m, n, ans, visited, newx, newy, path);
        path.pop_back();
    }

    // right
    newx = x;
    newy = y + 1;
    if (Allowed(newx, newy, m, visited, n))
    {
        path.push_back('R');
        solve(m, n, ans, visited, newx, newy, path);
        path.pop_back();
    }

    // left
    newx = x;
    newy = y - 1;
    if (Allowed(newx, newy, m, visited, n))
    {
        path.push_back('L');
        solve(m, n, ans, visited, newx, newy, path);
        path.pop_back();
    }

    visited[x][y] = 0;
}
vector<string> findPath(vector<vector<int>> &m, int n)
{
    if (m[0][0] == 0)
    {
        return {""};
    }
    vector<string> ans;
    vector<vector<int>> visited = m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            visited[i][j] = 0;
        }
    }
    string path = "";
    int srcx = 0, srcy = 0;
    solve(m, n, ans, visited, srcx, srcy, path);
    sort(ans.begin(), ans.end());
    return ans;
}
int main()
{
    vector<vector<int>> m = {{1, 0},
                             {1, 0}};
    int n = 2;
    vector<string> ans = findPath(m, n);
    printArr(ans);
    return 0;
}