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
vector<int> GetRight(vector<int> arr)
{
    int n = arr.size();
    vector<int> ans(n);
    stack<int> st;
    st.push(-1);
    for (int i = n - 1; i >= 0; i--)
    {
        int curr = arr[i];
        while (st.top() > curr)
        {
            st.pop();
        }
        ans[i] = st.top();
        st.push(curr);
    }
    return ans;
}
vector<int> GetLeft(vector<int> arr)
{
    int n = arr.size();
    vector<int> ans(n);
    stack<int> st;
    st.push(-1);
    for (int i = 0; i < n; i++)
    {
        int curr = arr[i];
        while (st.top() > curr)
        {
            st.pop();
        }
        ans[i] = st.top();
        st.push(curr);
    }
    return ans;
}
int main()
{
    vector<int> arr = {6, 8, 4, 2, 9, 1};
    vector<int> RightSmall = GetRight(arr);
    vector<int> LeftSmall = GetLeft(arr);
    print(LeftSmall);
    print(RightSmall);
    return 0;
}