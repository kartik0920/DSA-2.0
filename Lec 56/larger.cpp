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
        while (s.top() <= curr && s.top() != -1)
        {
            s.pop();
        }
        ans[i] = s.top();
        s.push(curr);
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
        while (s.top() <= curr && s.top() != -1)
        {
            s.pop();
        }
        ans[i] = s.top();
        s.push(curr);
    }
    return ans;
}
int main()
{
    vector<int> arr = {6, 8, 4, 2, 9, 1};
    vector<int> RightSmall = GetRight(arr, arr.size());
    vector<int> LeftSmall = GetLeft(arr, arr.size());
    print(LeftSmall);
    print(RightSmall);
    return 0;
}