#include <iostream>
using namespace std;
int main()
{
    // pattern 1
    /*
    int n;
    cout << "Enter n:";
    cin >> n;
    int i = 0;
    while (i < n)
    {
        int j = 0;
        while (j < n)
        {
            cout << "*" << ' ';
            j += 1;
        }
        cout << endl;
        i += 1;
    }
    */

    // Pattern 2
    int n;
    cout << "Enter n:";
    cin >> n;
    int i = 0;
    while (i < n)
    {
        int j = 0;
        while (j < n)
        {
            cout << i + 1 << " ";
            j += 1;
        }
        cout << endl;
        i += 1;
    }
    return 0;
}