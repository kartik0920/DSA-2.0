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
    for (int i = 1; i < size; i++)
    {
        int temp = arr[i];
        int j = i - 1;
        for (; j >= 0; j--)
        {
            if (arr[j] > temp)
            {
                arr[j + 1] = arr[j];
            }
            else
            {
                break;
            }
        }
        arr[j + 1] = temp;
    }
}
*/
void sort(int *arr, int size)
{
    for (int i = 1; i < size; i++)
    {
        int j = i - 1, temp = arr[i];
        while (j >= 0)
        {
            if (arr[j] > temp)
            {
                arr[j + 1] = arr[j];
            }
            else
            {
                break;
            }
            j--;
        }
        arr[j + 1] = temp;
    }
}
int main()
{

    int arr[] = {3
    , 12, 1};
    int size = sizeof(arr) / sizeof(arr[0]);
    cout << "b4 sort" << endl;
    printArr(arr, size);
    sort(arr, size);
    cout << "After sort" << endl;
    printArr(arr, size);

    return 0;
}