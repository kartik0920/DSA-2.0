#include <bits/stdc++.h>
#include <iostream>
using namespace std;
void print(vector<int> arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << ' ';
    }
    cout << endl;
}
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
int main()
{
    vector<int> heights = {4, 4, 4, 4};
    cout << largestRectangleArea(heights) << endl;
    return 0;
}