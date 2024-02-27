#include <iostream>
using namespace std;
int main()
{
    int a, b;
    char ch;
    cout << "Enter the character:";
    cin >> ch;
    cout << "Enter num1";
    cin >> a;
    cout << "Enter num2";
    cin >> b;
    switch (ch)
    {
    case '+':
        cout << a << ch << b << '=' << (a + b) << endl;
        ;
        break;
    case '-':
        cout << a << ch << b << '=' << (a - b) << endl;
        ;
        break;
    case '*':
        cout << a << ch << b << '=' << (a * b) << endl;
        ;
        break;
    case '/':
        cout << a << ch << b << '=' << (a / b) << endl;
        ;
        break;
    case '%':
        cout << a << ch << b << '=' << (a % b) << endl;
        break;

    default:
        cout << "Enter the correct operator" << endl;
        break;
    }
    return 0;
}