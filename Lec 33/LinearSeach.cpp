#include <iostream>
using namespace std;

bool ls(int *arr, int size, int key)
{
    if (size == 0)
    {
        return 0;
    }
    if (arr[0] == key)
    {
        return 1;
    }
    else
    {
        return ls(arr + 1, size - 1, key);
    }
}
int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int key = 51;
    int size = sizeof(arr) / sizeof(arr[0]);

    if (ls(arr, size, key))
    {
        cout << "Key is prensent" << endl;
    }
    else
    {
        cout << "Key is absent" << endl;
    }

    return 0;
}