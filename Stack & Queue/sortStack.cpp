#include <bits/stdc++.h>
#include <iostream>
using namespace std;
void print(stack<int> s)
{
    while (!s.empty())
    {
        cout << s.top() << ' ';
        s.pop();
    }
    cout << endl;
}

void sortInsert(stack<int> &st, int x)
{
    if (st.empty() || st.top() >= x)
    {
        st.push(x);
        return;
    }
    int y = st.top();
    st.pop();
    sortInsert(st, x);
    st.push(y);
}

void sort(stack<int> &st)
{
    if (st.empty())
    {
        return;
    }
    int x = st.top();
    st.pop();
    sort(st);
    sortInsert(st, x);
}

int main()
{
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(4);
    st.push(5);
    st.push(3);

    print(st);
    sort(st);
    print(st);

    return 0;
}