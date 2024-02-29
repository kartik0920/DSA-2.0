#include <iostream>
using namespace std;

int reachStairs(int n)
{
    if (n < 0)
    {
        return 0;
    }
    if (n == 0)
    {
        return 1;
    }
    return reachStairs(n - 1) + reachStairs(n - 2);
}
int main()
{
    cout << reachStairs(3) << endl;
    return 0;
}