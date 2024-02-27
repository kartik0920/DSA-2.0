#include <iostream>
using namespace std;
int main()
{
    int n = 2;
    bool Ispowerof2 = 0;
    double ans = 1;
    for (int i = 0; i <= 30; i++)
    {
        if (ans == n)
        {
            Ispowerof2 = 1;
        }
        ans *= 2;
        if (ans > n)
        {
            break;
        }
    }
    if (Ispowerof2)
    {
        cout << "It is power of 2" << endl;
    }
    else
    {
        cout << "It is not power of 2" << endl;
    }
    return 0;
}