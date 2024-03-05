#include <iostream>
using namespace std;

bool bs(int *arr, int s, int e, int key)
{
    if (s > e)
    {
        return 0;
    }
    int mid = s + (e - s) / 2;
    if (arr[mid] == key)
    {
        return 1;
    }
    else if (arr[mid] > key)
    {
        return bs(arr, s, mid - 1, key);
    }
    else
    {
        return bs(arr, mid + 1, e, key);
    }
}
int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int key = 12;
    int size = sizeof(arr) / sizeof(arr[0]);

    if (bs(arr, 0, size - 1, key))
    {
        cout << "Presnt" << endl;
    }
    else
    {
        cout << "Absent" << endl;
    }
    return 0;
}