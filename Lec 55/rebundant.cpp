#include <bits/stdc++.h>
#include <iostream>
using namespace std;
bool rebu(string str)
{
    stack<char> s;
    for (int i = 0; i < str.length(); i++)
    {
        char ch = str[i];
        if (ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/')
        {
            s.push(ch);
        }
        else
        {
            if (ch == ')')
            {
                bool isRebu = 1;
                while (s.top() != '(')
                {
                    char top = s.top();
                    if (top == '+' || top == '-' || top == '*' || top == '/')
                    {
                        isRebu = 0;
                    }
                    s.pop();
                }
                if (isRebu == 1)
                {
                    return 1;
                }
                s.pop();
            }
        }
    }
    return 0;
}
int main()
{
    string str = "((a+b)+(c))";
    cout << rebu(str) << endl;
    return 0;
}