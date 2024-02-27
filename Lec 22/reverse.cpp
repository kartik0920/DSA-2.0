#include <iostream>
using namespace std;
void reverse(string &str)
{
    int s = 0, e = str.length() - 1;
    while (s < e)
    {

        swap(str[s++], str[e--]);
    }
}
int main()
{
    string s;
    cin >> s;
    cout << s << endl;
    reverse(s);
    cout << s << endl;
    return 0;
}