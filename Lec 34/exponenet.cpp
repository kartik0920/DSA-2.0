#include <iostream>
using namespace std;

int pow(int a, int b)
{
    if (b == 0)
    {
        return 1;
    }
    if (b == 1)
    {
        return a;
    }
    int ans = pow(a, b / 2);

    if (b & 1 == 1)
    {
        return ans * ans * a;
    }
    else
    {
        return a * ans;
    }
}
int main()
{
    int a = 2, b = 3;
    cout << pow(a, b) << endl;
    return 0;
}