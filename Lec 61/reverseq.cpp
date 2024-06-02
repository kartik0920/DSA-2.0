#include <bits/stdc++.h>
#include <iostream>
using namespace std;
void print(queue<int> q)
{
    while (!q.empty())
    {
        cout << q.front() << ' ';
        q.pop();
    }
    cout << endl;
}
queue<int> reverse(queue<int> q)
{
    stack<int> s;
    while (!q.empty())
    {
        s.push(q.front());
        q.pop();
    }
    while (!s.empty())
    {
        q.push(s.top());
        s.pop();
    }
    return q;
}
int main()
{
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.pop();
    cout << "B4 reverse:";
    print(q);
    cout << "after reverse:";
    queue<int> r = reverse(q);
    print(r);
    return 0;
}