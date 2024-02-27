#include <iostream>
using namespace std;
/*
bool BinarySearch(int *arr, int size, int key)
{
    int s = 0, e = size - 1;
    int mid = s + (e - s) / 2;
    while (e >= s)
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
*/
int BinarySearch(int *arr, int size, int key)
{
    int s = 0, e = size - 1;
    int mid = s + (e - s) / 2;
    while (s <= e)
    {
        if (arr[mid] == key)
        {
            return mid;
        }
        else if (arr[mid] < key)
        {
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
        mid = s + (e - s) / 2;
    }
    return -1;
}
int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int size = sizeof(arr) / sizeof(arr[0]);
    int key = 5;
    /*
    bool found = BinarySearch(arr, size, key);
    if (found)
    {
        cout << "Present" << endl;
    }
    else
    {
        cout << "Absent" << endl;
    }
    */
    cout << key << " was present at index " << BinarySearch(arr, size, key) << endl;
    return 0;
}