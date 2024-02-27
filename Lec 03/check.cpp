#include <iostream>
using namespace std;
int main()
{
    int a;
    cout << "Enter a";
    cin >> a;
    if (a >= 0)
    {
        cout << "+ve" << endl;
    }
    else
    {
        cout << "-ve" << endl;
    }

    if (a > 0)
    {
        cout << "+ve" << endl;
    }
    else if (a == 0)
    {
        cout << "A is zero!" << endl;
    }
    else
    {
        cout << "-ve" << endl;
    }
    return 0;
}