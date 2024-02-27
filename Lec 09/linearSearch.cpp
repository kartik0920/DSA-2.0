#include <iostream>
using namespace std;
void printArr(int *arr, int size)
{
    cout << "Array is:  ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << ' ';
    }
    cout << endl;
}
bool LinearSeacrh(int *arr, int size, int key)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == key)
        {
            return 1;
        }
    }
    return 0;
}

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}
void Reversearr(int *arr, int size)
{
    int s = 0, e = size - 1;
    while (e >= s)
    {
        swap(arr[s], arr[e]);
        s++;
        e--;
    }
}
int main()
{
    int arr[] = {4, 2, 6, 2, 6, 0, 5, 13};
    int size = sizeof(arr) / sizeof(arr[0]);
    int key = 4;
    bool found = LinearSeacrh(arr, size, key);
    if (found)
    {
        cout << "Preasent" << endl;
    }
    else
    {
        cout << "absent" << endl;
    }

    cout << "Array b$ swap" << endl;
    printArr(arr, size);
    Reversearr(arr, size);
    cout << "Array after swap:" << endl;
    printArr(arr, size);
    return 0;
}