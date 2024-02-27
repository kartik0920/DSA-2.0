#include <iostream>
using namespace std;
int main()
{
    int n;
    cout << "Enter n:";
    cin >> n;
    // pattern 1
    /*
    int i = 0;
    while (i < n)
    {
        int j = 0;
        while (j < n)
        {
            cout << j + 1
                 << " ";
            j += 1;
        }
        cout << endl;
        i += 1;
    }
    */

    // pattern 2
    /*
    int i = 0;
    while (i < n)
    {
        int j = n;
        while (j > 0)
        {
            cout << j << " ";
            j--;
        }
        cout << endl;
        i += 1;
    }*/

    // pattern 3
    /*
    int i = 0, k = 1;
    while (i < n)
    {
        int j = n;
        while (j > 0)
        {
            cout << k++ << " ";
            j--;
        }
        cout << endl;
        i += 1;
    }*/

    // pattern 4
    /*
    int i = 0;
    while (i < n)
    {
        int j = 0;
        while (i >= j)
        {
            cout << "*"
                 << " ";
            j++;
        }
        cout << endl;
        i += 1;
    }
    */
    //    pattern 5
    /*
    int i = 0;
    while (i < n)
    {
        int j = 0;
        while (i >= j)
        {
            cout << i + 1
                 << " ";
            j++;
        }
        cout << endl;
        i += 1;
    }
    */

    //    pattern 6
    /*
    int i = 0, k = 1;
    while (i < n)
    {
        int j = 0;
        while (i >= j)
        {
            cout << k++ << " ";
            j++;
        }
        cout << endl;
        i += 1;
    }
    */

    //    patternn 7
    /*
    int i = 0;
    while (i < n)
    {
        int j = 0, k = i + 1;
        ;
        while (i >= j)
        {
            cout << k-- << " ";
            j++;
        }
        cout << endl;
        i += 1;
    }
    */

    //    pattern 8
    /*
    int i = 0;
    char ch = 'A';
    while (i < n)
    {
        int j = 0;
        while (j < n)
        {
            cout << ch << " ";
            j += 1;
        }
        ch++;
        cout << endl;
        i += 1;
    }
    */

    //    pattern 9
    /*
    int i = 0;
    while (i < n)
    {
        char ch = 'A';
        int j = 0;
        while (j < n)
        {
            cout << ch++ << " ";
            j += 1;
        }
        cout << endl;
        i += 1;
    }*/

    // pattern 10
    int i = 0;
    char ch = 'A';
    while (i < n)
    {
        int j = 0;
        while (j < n)
        {
            cout << ch++ << " ";
            j += 1;
        }
        cout << endl;
        i += 1;
    }
    return 0;
}