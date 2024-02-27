#include <iostream>
using namespace std;
int sqrt(int n)
{
    int s = 0, e = n;
    int mid = s + (e - s) / 2, ans = 0;
    while (e >= s)
    {
        if (mid * mid == n)
        {
            return mid;
        }
        else if (mid * mid < n)
        {
            ans = mid;
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
        mid = s + (e - s) / 2;
    }
    return ans;
}
int main()
{
    int n = 17;
    cout << sqrt(n) << endl;
    return 0;
}