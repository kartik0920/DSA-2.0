#include <iostream>
using namespace std;

int gcd(int a, int b)
{
    if (a == 0)
    {
        return b;
    }
    if (b == 0)
    {
        return a;
    }
    while (a != b)
    {
        if (a > b)
        {
            a = a - b;
        }
        else
        {
            b = b - a;
        }
    }
    return a;
}
int lcm(int a, int b)
{
    int poduct = a * b;
    int factor = gcd(a, b);
    int lcm = poduct / factor;
    return lcm;
}
int main()
{
    int a = 3, b = 7;
    cout << lcm(a, b) << endl;
    return 0;
}