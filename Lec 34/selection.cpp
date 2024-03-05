#include <iostream>
using namespace std;

void printArr(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << ' ';
    }
    cout << endl;
}
/*

void sort(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        int min_index = i;
        for (int j = i + 1; j < size; j++)
        {
            if (arr[min_index] > arr[j])
            {
                min_index = j;
            }
        }
        swap(arr[i], arr[min_index]);
    }
}
*/
void sort(int *arr, int size)
{
    if (size == 0)
    {
        return;
    }
    int min_index = 0;
    for (int i = 1; i < size; i++)
    {
        if (arr[i] < arr[min_index])
        {
            min_index = i;
        }
    }
    swap(arr[0], arr[min_index]);
    sort(arr, size - 1);
}
int main()
{
    int arr[] = {5, -3, 1};
    int size = sizeof(arr) / sizeof(arr[0]);
    sort(arr, size);
    printArr(arr, size);
    return 0;
}