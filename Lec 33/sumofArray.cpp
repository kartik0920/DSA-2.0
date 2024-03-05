#include <iostream>
using namespace std;

int getsum(int *arr, int size)
{
    if (size == 0)
    {
        return 0;
    }
    if (size == 1)
    {
        return arr[0];
    }

    return arr[0] + getsum(arr + 1, size - 1);
}
int main()
{
    int arr[] = {1, -1, 2, 3, 4, 5, 6};
    int size = sizeof(arr) / sizeof(arr[0]);
    cout << getsum(arr, size) << endl;
    return 0;
}