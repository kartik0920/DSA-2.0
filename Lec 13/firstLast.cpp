#include <iostream>
using namespace std;
int firstocc(int *arr, int size, int key)
{
    int s = 0, e = size - 1;
    int mid = s + (e - s) / 2;
    int ans = -1;
    while (s <= e)
    {
        if (arr[mid] == key)
        {
            ans = mid;
            e = mid - 1;
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
    return ans;
}
int lastocc(int *arr, int size, int key)
{
    int s = 0, e = size - 1;
    int mid = s + (e - s) / 2;
    int ans = -1;
    while (s <= e)
    {
        if (arr[mid] == key)
        {
            ans = mid;
            s = mid + 1;
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
    return ans;
}
int main()
{
    int arr[] = {1, 1, 1, 2, 3, 4, 5, 5};
    int n = 1;
    int size = sizeof(arr) / sizeof(arr[0]);
    int first = firstocc(arr, size, n);
    cout << "Fist occurence of " << n << " is " << first << endl;
    int last = lastocc(arr, size, n);
    cout << "last occurence of " << n << " is " << last << endl;
    cout << last - first + 1 << endl;
    return 0;
}