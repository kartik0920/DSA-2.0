#include <bits/stdc++.h>
#include <iostream>
using namespace std;
void printArr(vector<vector<int>> arr)
{
    for (auto i : arr)
    {
        for (auto j : i)
        {
            cout << j << ' ';
        }
        cout << endl;
    }
}
void printArr(vector<int> arr)
{
}
void AddSolution(vector<vector<int>> &ans, vector<vector<int>> board)
{
    vector<int> temp;
    for (auto i : board)
    {
        for (auto j : i)
        {
            temp.push_back(j);
        }
    }
    ans.push_back(temp);
}

bool IsSafe(int row, int col, int n, vector<vector<int>> board)
{
    int x = row, y = col;
    // row check
    while (y >= 0)
    {
        if (board[x][y] == 1)
        {
            return 0;
        }
        y--;
    }

    // top left diagonal
    y = col;
    while (x >= 0 && y >= 0)
    {
        if (board[x][y] == 1)
        {
            return 0;
        }
        x--;
        y--;
    }

    x = row, y = col;

    while (x < n && y >= 0)
    {
        if (board[x][y] == 1)
        {
            return 0;
        }
        x++;
        y--;
    }

    return 1;
}
void solve(int col, int n, vector<vector<int>> &ans, vector<vector<int>> &board)
{
    if (col == n)
    {
        AddSolution(ans, board);
        return;
    }

    for (int row = 0; row < n; row++)
    {
        if (IsSafe(row, col, n, board))
        {
            board[row][col] = 1;
            solve(col + 1, n, ans, board);
            board[row][col] = 0;
        }
    }
}

vector<vector<int>> Nqueen(int n)
{
    vector<vector<int>> ans;
    vector<vector<int>> board(n, vector<int>(n, 0));
    int col = 0;
    solve(0, n, ans, board);
    return ans;
}
int main()
{

    int n = 4;
    vector<vector<int>> ans = Nqueen(n);
    printArr(ans);
    printArr(ans[0]);
    return 0;
}