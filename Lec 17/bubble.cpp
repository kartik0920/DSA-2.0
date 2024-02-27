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
void sort(int *arr, int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        bool Issorted = 0;
        for (int j = 0; j < size - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                Issorted = 1;
            }
        }
        if (!Issorted)
        {
            break;
        }
    }
}
int main()
{

    int arr[] = {32, 12, 1};
    int size = sizeof(arr) / sizeof(arr[0]);
    cout << "b4 sort" << endl;
    printArr(arr, size);
    sort(arr, size);
    cout << "After sort" << endl;
    printArr(arr, size);

    return 0;
}