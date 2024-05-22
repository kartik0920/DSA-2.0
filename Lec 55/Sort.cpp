#include <bits/stdc++.h>
using namespace std;
void print(stack<int> st)
{
    while (!st.empty())
    {
        cout << st.top() << ' ';
        st.pop();
    }
    cout << endl;
}
void SortInsert(stack<int> &st, int d)
{
    if (st.empty() || st.top() < d)
    {
        st.push(d);
        return;
    }
    int num = st.top();
    st.pop();
    SortInsert(st, d);
    st.push(num);
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
    SortInsert(st, x);
}
int main()
{
    stack<int> S;
    S.push(4);
    S.push(-2);
    S.push(5);
    S.push(41);
    S.push(1);
    sort(S);
    print(S);
    return 0;
}