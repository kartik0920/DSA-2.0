#include <iostream>
using namespace std;

int getPivot(int *arr, int size)
{
    int s = 0, e = size - 1;
    int mid = s + (e - s) / 2;
    while (e > s)
    {
        if (arr[mid] >= arr[0])
        {
            s = mid + 1;
        }
        else
        {
            e = mid;
        }
        mid = s + (e - s) / 2;
    }
    return s;
}

bool BinarySearch(int *arr, int s, int e, int key)
{
    int mid = s + (e - s) / 2;
    while (s <= e)
    {
        if (arr[mid] == key)
        {
            return 1;
        }
        else if (arr[mid] > key)
        {
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
        mid = s + (e - s) / 2;
    }
    return 0;
}
bool SearchPivot(int *arr, int size, int key)
{
    int pivot = getPivot(arr, size);
    if (arr[0] <= key)
    {
        return BinarySearch(arr, 0, pivot - 1, key);
    }
    else
    {
        return BinarySearch(arr, pivot, size - 1, key);
    }
}
int main()
{
    int arr[] = {1};
    int size = sizeof(arr) / sizeof(arr[0]);

    int key = 1;
    bool found = SearchPivot(arr, size, key);
    if (found)
    {
        cout << "Present!" << endl;
    }
    else
    {
        cout << "Absent!" << endl;
    }
    return 0;
}