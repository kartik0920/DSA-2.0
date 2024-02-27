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
    for (int i = 0; i < size; i++)
    {
        int min_index = i;
        for (int j = i + 1; j < size; j++)
        {
            if (arr[j] < arr[min_index])
            {
                min_index = j;
            }
        }
        swap(arr[i], arr[min_index]);
    }
}
using namespace std;
int main()
{
    int arr[] = {1, 5, 4, 2};
    int size = sizeof(arr) / sizeof(arr[0]);
    sort(arr, size);
    printArr(arr, size);
    return 0;
}