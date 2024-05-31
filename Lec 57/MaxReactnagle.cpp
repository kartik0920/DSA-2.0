#include <bits/stdc++.h>
#include <iostream>
using namespace std;

vector<int> GetRight(vector<int> arr, int n)
{
    vector<int> ans(n);
    stack<int> s;
    s.push(-1);
    for (int i = n - 1; i >= 0; i--)
    {
        int curr = arr[i];
        while (arr[s.top()] >= curr && s.top() != -1)
        {
            s.pop();
        }
        ans[i] = s.top();
        s.push(i);
    }
    return ans;
}
vector<int> GetLeft(vector<int> arr, int n)
{
    vector<int> ans(n);
    stack<int> s;
    s.push(-1);
    for (int i = 0; i < n; i++)
    {
        int curr = arr[i];
        while (arr[s.top()] >= curr && s.top() != -1)
        {
            s.pop();
        }
        ans[i] = s.top();
        s.push(i);
    }
    return ans;
}
int largestRectangleArea(vector<int> h)
{
    int n = h.size();
    vector<int> left = GetLeft(h, n);
    vector<int> right = GetRight(h, n);
    int area = -1;
    for (int i = 0; i < n; i++)
    {
        int l = h[i];
        if (right[i] == -1)
        {
            right[i] = n;
        }
        int b = right[i] - left[i] - 1;
        area = max(area, l * b);
    }
    return area;
}
int maximalRectangle(vector<vector<char>> &matrix)
{
    vector<vector<int>> mat;
    for (int i = 0; i < matrix.size(); i++)
    {
        vector<int> l;
        vector<char> temp = matrix[i];
        for (int j = 0; j < temp.size(); j++)
        {
            if (temp[j] == '0')
            {
                l.push_back(0);
            }
            else
            {
                l.push_back(1);
            }
        }
        mat.push_back(l);
    }
    int n = mat.size();
    int m = mat[0].size();
    cout << n << "&&&" << m << endl;
    int area = largestRectangleArea(mat[0]);
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (mat[i][j])
            {
                mat[i][j] = mat[i][j] + mat[i - 1][j];
            }
            else
            {
                mat[i][j] = 0;
            }
        }
        int newA = largestRectangleArea(mat[i]);
        area = max(area, newA);
    }
    return area;
}
int main()
{

    vector<vector<char>> matrix;
    matrix = {{'0', '0'},
              {'0', '0'}};k
    cout << maximalRectangle(matrix) << endl;
    return 0;
}