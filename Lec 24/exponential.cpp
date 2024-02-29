#include <iostream>
using namespace std;

int expo(int a, int b)
{
    int result = 1;
    while (b > 0)
    {
        if (b & 1 == 1)
        {
            result *= a;
        }
        a = a * a;
        b = b >> 1;
    }
    return result;
}
int main()
{
    int a = 4, b = 2;
    cout << expo(a, b) << endl;
    return 0;
}