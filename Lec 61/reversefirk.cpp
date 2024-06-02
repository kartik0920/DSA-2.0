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
queue<int> modifyQueue(queue<int> q, int k)
{
    stack<int> s;
    int size = q.size();
    for (int i = 0; i < k; i++)
    {
        int v = q.front();
        q.pop();
        s.push(v);
    }
    while (!s.empty())
    {
        q.push(s.top());
        s.pop();
    }
    int t = size - k;
    while (t != 0)
    {
        t--;
        int v = q.front();
        q.push(v);
        q.pop();
    }
    return q;
}
int main()
{
    queue<int> q;
    q.push(4);
    q.push(3);
    q.push(2);
    q.push(1);
    // q.push(5);
    print(q);
    q = modifyQueue(q, 4);
    print(q);
    return 0;
}