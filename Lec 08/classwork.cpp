#include <iostream>
using namespace std;
int expo(int base, int power)
{
    int ans = 1;
    while (power != 0)
    {
        ans = base * ans;
        power -= 1;
    }
    return ans;
}

bool IsOdd(int n)
{
    return n & 1 == 1 ? 1 : 0;
}

int fact(int n)
{
    int fact = 1;
    while (n != 0)
    {
        fact *= n;
        n -= 1;
    }
    return fact;
}

int nCr(int n, int r)
{
    int num = n;
    int den = fact(n) * fact(n - r);
    return num / den;
}

bool IsPrime(int n)
{
    for (int i = 2; i < n; i++)
    {
        if (n % i == 0)
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    /*
    int base, power;
    cout << "Enter base:";
    cin >> base;
    cout << "Enter power:";
    cin >> power;
    int ans = expo(base, power);
    cout << ans << endl;
    */

    /*
     int n = 1;
     bool Odd = IsOdd(n);
     if (Odd)
     {
         cout << "It is odd number" << endl;
     }
     else
     {
         cout << "It is even number" << endl;
     }
     */

    /*
        int n = 3;
        cout << fact(n) << endl;
    */

    /*
     int n = 5, r = 3;
     cout << nCr(n, r) << endl;
     */

    // prime or not

    int n = 13;
    bool prime = IsPrime(n);
    if (prime)
    {
        cout << "It is a prime number" << endl;
    }
    else
    {
        cout << "It is not a prime number" << endl;
    }

    return 0;
}