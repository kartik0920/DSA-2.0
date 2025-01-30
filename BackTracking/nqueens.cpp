#include <bits/stdc++.h>
#include <iostream>
using namespace std;

void printArr(vector<vector<int>> arr)
{
    cout << "HERE IS ARR:" << endl;
    ;
    for (auto i : arr)
    {
        for (auto j : i)
        {
            cout << j << ' ';
        }
        cout << endl;
    }
}

void addSolution(vector<vector<int>> &ans, vector<vector<int>> board)
{
    for (auto i : board)
    {
        vector<int> temp;
        for (auto j : i)
        {
            temp.push_back(j);
        }
        ans.push_back(temp);
    }
}

bool isSafe(int row, int col, vector<vector<int>> board, int n)
{
    int x = row, y = col;
    while (y >= 0)
    {
        if (board[x][y] == 1)
        {
            return 0;
        }
        y--;
    }

    x = row, y = col;
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

void solve(int col, vector<vector<int>> &ans, vector<vector<int>> board, int n)
{
    if (col == n)
    {
        addSolution(ans, board);
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if (isSafe(i, col, board, n))
        {
            board[i][col] = 1;
            solve(col + 1, ans, board, n);
            board[i][col] = 0;
        }
    }
}

vector<vector<int>> nQuenss(int n)
{
    vector<vector<int>> ans;
    vector<vector<int>> board(n, vector<int>(n, 0));
    solve(0, ans, board, n);
    return ans;
}

int main()
{
    int n = 4;
    vector<vector<int>> ans = nQuenss(n);
    printArr(ans);
    return 0;
}