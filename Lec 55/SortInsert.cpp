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
    int x = st.top();
    st.pop();
    SortInsert(st, d);
    st.push(x);
}
int main()
{
    stack<int> S;
    S.push(1);
    S.push(2);
    S.push(3);
    S.push(4);
    S.push(6);
    SortInsert(S, -1);
    print(S);
    return 0;
}