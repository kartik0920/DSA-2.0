#include <iostream>
using namespace std;

bool getSorted(int *arr, int size)
{
    if (size == 0 || size == 1)
    {
        return 1;
    }
    if (arr[0] > arr[1])
    {
        return 0;
    }
    else
    {
        return getSorted(arr + 1, size - 1);
    }
}
int main()
{
    int arr[] = {2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);

    bool Issorted = getSorted(arr, size);
    if (Issorted)
    {
        cout << "It is sorted" << endl;
    }
    else
    {
        cout << "It is not sorted" << endl;
    }
    return 0;
}