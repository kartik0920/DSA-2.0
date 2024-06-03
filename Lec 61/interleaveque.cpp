#include <bits/stdc++.h>
#include <iostream>
using namespace std;
vector<int> rearrangeQueue(queue<int> &q)
{
    queue<int> nq;
    int size = q.size();
    for (int i = 0; i < (size / 2); i++)
    {
        nq.push(q.front());
        q.pop();
    }

    while (!nq.empty())
    {
        int v = nq.front();
        q.push(v);
        nq.pop();
        v = q.front();
        q.push(v);
        q.pop();
    }
    vector<int> ans;
    while (!q.empty())
    {
        ans.push_back(q.front());
        q.pop();
    }
    return ans;
}
int main()
{
    cout << ceil(15 / 2) << endl;
    return 0;
}