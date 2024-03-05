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

/*/
void sort(int *arr, int size)
{
    for (int i = 1; i < size; i++)
    {
        int j = i - 1, temp = arr[i];
        for (; j >= 0; j--)
        {
            if (temp < arr[j - 1])
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
    if (size <= 1)
    {
        return;
    }
    sort(arr, size - 1);
    int temp = arr[size - 1];
    int i = size - 2;
    for (; i >= 0 && arr[i] > temp; i--)
    {

        arr[i + 1] = arr[i];
    }
    arr[i + 1] = temp;
}

int main()
{
    int arr[] = {5, 12, -3, 1, 12};
    int size = sizeof(arr) / sizeof(arr[0]);
    sort(arr, size);
    printArr(arr, size);
    return 0;
}