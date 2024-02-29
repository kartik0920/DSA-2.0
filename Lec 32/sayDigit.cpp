#include <iostream>
using namespace std;

void SayDigit(string *names, int n)
{
    if (n == 0)
    {
        return;
    }
    SayDigit(names, n / 10);
    cout << names[n % 10] << ' ';
}
int main()
{
    string names[10] = {"zero", "one", "two", "three ", " four ", " five ", "six", "seven", "eight", "nine"};
    int n = 456;
    SayDigit(names, n);
    cout << endl;
    return 0;
}