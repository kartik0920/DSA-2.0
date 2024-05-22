#include <bits/stdc++.h>
#include <iostream>
using namespace std;
void reverse(string &str)
{
    stack<char> s;
    string ans = "";
    for (int i = 0; i < str.length(); i++)
    {
        char ch = str[i];
        s.push(ch);
    }
    while (!s.empty())
    {
        ans.push_back(s.top());
        s.pop();
    }
    str = ans;
}
int main()
{
    string str = "Kartik";
    reverse(str);
    cout << str << endl;
    return 0;
}