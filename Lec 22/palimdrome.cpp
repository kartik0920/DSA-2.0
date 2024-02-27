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

void reverse(string str, int s, int e)
{
    while (e >= s)
    {
        swap(str[s++], str[e--]);
    }
}
void checkpali(string &str)
{
    int s = 0, e = 0, len = str.length() - 1;
    while (e < len )
    {
        e = str.find(' ');
        reverse(str, s, e);
        s = e + 1;
        e++;
    }
}
int main()
{
    string str = "my name is kartik";
    checkpali(str);
    cout << str << endl;
    // // cout << toLower('a');
    return 0;
}