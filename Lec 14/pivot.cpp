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
int main()
{
    int arr[] = {17, 2, 3};
    int size = sizeof(arr) / sizeof(arr[0]);
    int pivot = getPivot(arr, size);
    cout << "pivot is " << arr[pivot] << endl;
    return 0;
}