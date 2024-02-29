#include <iostream>
using namespace std;

int fibo(int n)
{
    if (n == 0)
    {
        return 0;
    }
    if (n == 1)
    {
        return 1;
    }

    return fibo(n - 1) + fibo(n - 2);
}
int main()
{
    // 0 1 1 2 3 5 8
    cout << fibo(6) << endl;
    return 0;
}