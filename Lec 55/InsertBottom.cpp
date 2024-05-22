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
void solve(stack<int> &st, int data)
{
    if (st.empty())
    {
        st.push(data);
        return;
    }
    int x = st.top();
    st.pop();
    solve(st, data);
    st.push(x);
}

void insert(stack<int> &st, int data)
{
    int size = st.size();
    solve(st, data);
}
int main()
{
    stack<int> S;
    S.push(1);
    S.push(2);
    S.push(3);
    S.push(4);
    S.push(5);
    insert(S, 0);
    print(S);
    return 0;
}