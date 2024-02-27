#include <iostream>
using namespace std;
int main()
{
    int n;
    cout << "Enter n:";
    cin >> n;
    int i = 02;
    bool Isprime = 1;
    while (i < n)
    {
        if (n % i == 0)
        {
            Isprime = 0;
        }
        i += 1;
    }
    if (Isprime)
    {
        cout << "number is prime" << endl;
    }
    else
    {
        cout << "Number is not prime" << endl;
    }
    return 0;
}