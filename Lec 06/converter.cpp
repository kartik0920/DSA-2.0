#include <cmath>
#include <iostream>
using namespace std;
int main()
{
    // decimal to binary
    /*
    int n = 2;
     
    cout << ans << endl;
    */

    //    binary to decimal
    int n = 110;
    int ans = 0;
    int i = 0;
    while (n != 0)
    {
        int digit = n % 10;
        if (digit == 1)
        {
            ans = ans + pow(2, i);
        }
        i += 1;
        n /= 10;
    }
    cout << ans << endl;
    return 0;
}