#include <iostream>
using namespace std;
int main()
{

    // sum of first n
    /*
    int n = 0;
    cout << "Enter n:";
    int sum = 0;
    cin >> n;
    for (int i = 0; i <=n n; i++)
    {
        // cout << i << ' ';
        sum += i;
    }
    cout << endl
         << "Sum is "
         << sum << endl;
    */

    //    fibonaci serioes
    /*
    int n;
    cout << "Enter n:";
    cin >> n;

    int first = 0, second = 1;
    if (n >= 1)
    {
        cout << first << " ";
        if (n >= 2)
        {
            cout << second << " ";
        }
    }
    for (int i = 2; i < n; i++)
    {
        int third = first + second;
        cout << third << ' ';
        first = second;
        second = third;
    }
    cout << endl;
    */

    // prime number
    int n = 1;
    cout << "Enter n:";
    cin >> n;
    bool isPrime = 1;
    for (int i = 2; i < n; i++)
    {
        if (n % i == 0)
        {
            isPrime = 0;
            break;
        }
    }
    if (isPrime)
    {
        cout << "Is is prime number " << endl;
    }
    else
    {
        cout << "It is not prime number" << endl;
    }
    return 0;
}