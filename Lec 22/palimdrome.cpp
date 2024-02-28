#include <iostream>
using namespace std;

bool valid(char ch)
{
    if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9'))
    {
        return 1;
    }
    return 0;
}
char toLower(char ch)
{
    if ((ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9'))
    {
        return ch;
    }
    else
    {
        char temp = ch - 'A' + 'a';
        return temp;
    }
}
bool isPalindrome(string str)
{
    int s = 0, e = str.length() - 1;
    string temp;
    for (int i = 0; i < str.length(); i++)
    {
        if (valid(str[i]))
        {
            temp.push_back(str[i]);
        }
    }

    for (int i = 0; i < temp.length(); i++)
    {
        temp[i] = toLower(temp[i]);
    }
    e = temp.length() - 1;
    while (e > s)
    {
        if (temp[s] != temp[e])
        {
            return 0;
        }
        s++;
        e--;
    }
    return 1;
}
int main()
{
    string str = "kartik i kiTrak";
    bool found = isPalindrome(str);
    if (found)
    {
        cout << "Its is plaimdrome" << endl;
    }
    else
    {
        cout << "It is not palimdrome" << endl;
    }
    // // cout << toLower('a');
    return 0;
}