#include <iostream>
#include <vector>
using namespace std;
int PrimeCount(int n)
{
    vector<bool> map(n + 1, 1);
    int count = 0;
    for (int i = 2; i < n; i++)
    {
        if (map[i])
        {
            count++;
            for (int j = i * 2; j < n; j += i)
            {
                map[j] = 0;
            }
        }
    }
    return count;
}
int main()
{
    int n = 6;
    cout << "no of prime number are" << PrimeCount(n) << endl;
    return 0;
}