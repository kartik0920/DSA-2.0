#include <iostream>
using namespace std;
int peak(int *arr, int size)
{
    int s = 0, e = size - 1;
    int mid = s + (e - s) / 2;
    while (e >= s)
    {
        if (s == e)
        {
            return arr[s];
        }
        else if (arr[mid] > arr[mid + 1])
        {
            e = mid;
        }
        else
        {
            s = mid + 1;
        }
        mid = s + (e - s) / 2;
    }
    return -1;
}
int main()
{
    int arr[] = {1, 2, 3, 4, 11, 10, 2, 1};
    int size = sizeof(arr) / sizeof(arr[0]);
    cout << "Peak of the array is " << peak(arr, size) << endl;

    return 0;
}