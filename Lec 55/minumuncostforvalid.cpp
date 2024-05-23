#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int mincost(string str)
{
    if (str.length() & 1)
    {
        return -1;
    }
    stack<char> s;
    for (int i = 0; i < str.length(); i++)
    {
        char ch = str[i];
        if (ch == '{')
        {
            s.push(ch);
        }
        else
        {
            if (!s.empty() && s.top() == '{')
                s.pop();
            else
                s.push(ch);
        }
    }
    int a = 0, b = 0;
    while (!s.empty())
    {
        char top = s.top();
        top == '{' ? a++ : b++;
        s.pop();
    }
    return ((a + 1) / 2) + ((b + 1) / 2);
}
int main()
{
    string str = "{{{}}}}}";
    cout << mincost(str) << endl;
    return 0;
}