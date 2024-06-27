#include <bits/stdc++.h>
#include <iostream>
using namespace std;

void printArr(vector<int> arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << ' ';
    }
    cout << endl;
}

void heapify(vector<int> &arr, int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = left + 1;

    if (left < n && arr[largest] > arr[left])
    {
        largest = left;
    }
    if (right < n && arr[largest] > arr[right])
    {
        largest = right;
    }

    if (largest != i)
    {
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
}

void BuildHeap(vector<int> &arr)
{
    int n = arr.size();
    for (int i = (n / 2) - 1; i >= 0; i--)
    {
        heapify(arr, n, i);
    }
}

void HeapSort(vector<int> &arr)
{
    int n = arr.size();
    BuildHeap(arr);

    for (int i = n - 1; i >= 0; i--)
    {
        swap(arr[0], arr[i]);
        heapify(arr, n, i);
    }
}

int main()
{
    vector<int> arr = {5, 567, 3, 2, 1};
    HeapSort(arr);

    printArr(arr);
    return 0;
}