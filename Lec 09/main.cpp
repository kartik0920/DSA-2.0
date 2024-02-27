#include <iostream>
using namespace std;
void printArr(int *arr, int size)
{
    cout << "Array is ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << ' ';
    }
    cout << endl;
}

int getMin(int *arr, int size)
{
    int min = arr[0];
    for (int i = 0; i < size; i++)
    {
        if (min > arr[i])
        {
            min = arr[i];
        }
    }
    return min;
}

int getMax(int *arr, int size)
{
    int max = arr[0];
    for (int i = 0; i < size; i++)
    {
        if (max < arr[i])
        {
            max = arr[i];
        }
    }
    return max;
}
int main()
{
    int arr[] = {15, 2, -3, 4, 1};
    int size = sizeof(arr) / sizeof(arr[0]);
    printArr(arr, size);
    cout << "Mini number is " << getMin(arr, size) << endl;
    cout << "MAx number is " << getMax(arr, size) << endl;
    return 0;
}