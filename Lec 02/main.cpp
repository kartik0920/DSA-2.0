#include <iostream>
using namespace std;
int main()
{
    int number = 0;
    cin >> number;
    if (number >= 1)
    {
        cout << "number is positive ";
    }
    else if (number <= -1)
    {
        cout << "number is negative";
    }
    else
    {
        cout << "number is zero";
    }
    cout << "hello kartik";
    return 0;
}