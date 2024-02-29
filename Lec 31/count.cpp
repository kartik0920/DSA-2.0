#include <iostream>
using namespace std;

void print(int n)
{
    if (n == 0)
    {
        return;
    }
    // for 5 4 3 2 1
    /*
    cout << n << " ";
    print(n - 1);
    */

    //    for 1 2 3
    print(n - 1);
    cout << n << " ";
}
int main()
{
    print(5);
    cout << endl;
    return 0;
}