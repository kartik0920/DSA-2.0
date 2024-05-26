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
vector<int> right(vector<int> arr)
{
    int n = arr.size();
    vector<int> ans(n);
    stack<int> st;
    st.push(-1);
    for (int i = n - 1; i >= 0; i--)
    {
        int curr = arr[i];
        while (arr[st.top()] >= curr && st.top() != -1)
        {
            st.pop();
        }
        ans[i] = st.top();
        st.push(i);
    }
    return ans;
}
vector<int> left(vector<int> arr)
{
    int n = arr.size();
    vector<int> ans(n);
    stack<int> st;
    st.push(-1);
    for (int i = 0; i < n; i++)
    {
        int curr = arr[i];
        while (arr[st.top()] >= curr && st.top() != -1)
        {
            st.pop();
        }
        ans[i] = st.top();
        st.push(i);
    }
    return ans;
}
int largestRectangleArea(vector<int> h)
{
    // int n = h.size();
    vector<int> p = left(h);
    vector<int> n = right(h);
    int a = INT16_MIN;
    for (int i = 0; i < h.size(); i++)
    {
        int l = h[i];
        if (n[i] == -1)
        {
            n[i] = h.size();
        }
        int b = n[i] - p[i] - 1;
        int newa = l * b;
        a = max(a, newa);
    }
    return a;
}
int main()
{
    vector<int> heights = {2, 4};
    cout << largestRectangleArea(heights) << endl;
    return 0;
}