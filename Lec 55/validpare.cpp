#include <bits/stdc++.h>
#include <iostream>
using namespace std;
bool match(char ch, stack<char> st)
{
    if ((ch == ']' && st.top() == '[') || (ch == ')' && st.top() == '(') || (ch == '}' && st.top() == '{'))
    {
        return 1;
    }
    return 0;
}
bool isValid(string s)
{
    stack<char> st;
    for (int i = 0; i < s.length(); i++)
    {
        char ch = s[i];
        if ((ch == '{') || (ch == '[') || (ch == '('))
        {
            st.push(ch);
        }
        else
        {
            if (!st.empty())
                if (match(ch, st))
                {
                    st.pop();
                }
                else
                {
                    return 0;
                }
            else
            {
                return 0;
            }
        }
    }
    return st.empty() ? 1 : 0;
}

int main()
{
    string str = "[]";
    cout << isValid(str) << endl;
    return 0;
}