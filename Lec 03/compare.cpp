#include <iostream>
using namespace std;
int main()
{
    int a = 0, b = 0;
    cout << "Enter a:";
    cin >> a;
    cout << "Enter b:";
    cin >> b;
    if (a > b)
    {
        cout << "A is bigger" << endl;
    }
    else
    {
        cout << "A is smaller" << endl;
    }
    return 0;
}