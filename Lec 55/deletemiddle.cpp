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
void solve(stack<int> &st, int cnt, int size)
{
    if (cnt == (size / 2))
    {
        st.pop();
        return;
    }
    int x = st.top();
    st.pop();
    solve(st, cnt + 1, size);
    st.push(x);
}
void deleteMiddle(stack<int> &st, int size)
{
    int cnt = 0;
    solve(st, cnt, size);
}
int main()
{
    stack<int> S;
    S.push(1);
    S.push(2);
    S.push(3);
    S.push(4);
    S.push(5);
    S.push(6);
    print(S);
    int size = S.size();
    cout << size << endl;
    deleteMiddle(S, size);
    print(S);
    return 0;
}