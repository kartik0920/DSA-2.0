#include <iostream>
using namespace std;

bool checkpali(string str, int s, int e)
{
    if (s > e)
    {
        return 1;
    }
    if (str[s] != str[e])
    {
        return 0;
    }
    else
    {
        return checkpali(str, s + 1, e - 1);
    }
}
int main()
{
    string str = "kartik";
    bool isPalimdrome = checkpali(str, 0, str.length() - 1);
    if (isPalimdrome)
    {
        cout << "It is true" << endl;
    }
    else
    {
        cout << "It is false" << endl;
    }
    return 0;
}