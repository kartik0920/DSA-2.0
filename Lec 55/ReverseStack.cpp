#include <iostream>
#include <stack>
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
void InsertBottom(stack<int> &st, int x)
{
    if (st.empty())
    {
        st.push(x);
        return;
    }
    int num = st.top();
    st.pop();
    InsertBottom(st, x);
    st.push(num);
}
void reverse(stack<int> &st)
{
    if (st.empty())
    {
        return;
    }
    int x = st.top();
    st.pop();
    reverse(st);
    InsertBottom(st, x);
}
int main()
{
    stack<int> S;
    S.push(1);
    S.push(2);
    S.push(3);
    S.push(4);
    S.push(5);
    print(S);
    reverse(S);
    print(S);
    return 0;
}