#include <iostream>
using namespace std;
int main()
{
    int n;
    cout << "Enter n:";
    cin >> n;
    int i = 0;
    int sum = 0;
    while (i <= n)
    {
        sum += i;
        cout << i << " ";
        i += 1;
    }
    cout << "\nSum is :" << sum << endl;

    return 0;
}