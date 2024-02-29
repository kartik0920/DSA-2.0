#include <iostream>
using namespace std;

int pow2(int n)
{
    if (n == 0)
    {
        return 1;
    }
    return 2 * pow2(n - 1);
}
int main()
{
    cout << pow2(2) << endl;
    return 0;
}