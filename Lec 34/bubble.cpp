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
        for (int j = 0; j < size - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}*/

void sort(int *arr, int size)
{
    if (size == 0)
    {
        return;
    }
    for (int i = 0; i < size; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            swap(arr[i], arr[i + 1]);
        }
    }
    sort(arr, size - 1);
}
int main()
{
    int arr[] = {5, 3, 1};
    int size = sizeof(arr) / sizeof(arr[0]);
    sort(arr, size);
    printArr(arr, size);
    return 0;
}