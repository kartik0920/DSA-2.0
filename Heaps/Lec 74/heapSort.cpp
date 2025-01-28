#include <bits/stdc++.h>
#include <iostream>
using namespace std;

void printArr(vector<int> arr)
{
    for (auto i : arr)
    {
        cout << i << " ";
    }
    cout << endl;
}

void heapify(vector<int> &arr, int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = left + 1;

    if (left <= n && arr[largest] < arr[left])
    {
        largest = left;
    }
    if (right <= n && arr[largest] < arr[right])
    {
        largest = right;
    }

    if (largest != i)
    {
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
}

vector<int> heapSort(vector<int> arr)
{
    int n = arr.size();
    for (int i = (n / 2) - 1; i >= 0; i--)
    {
        heapify(arr, n, i);
    }

    int t = n - 1;

    while (t > 0)
    {
        swap(arr[0], arr[t--]);
        heapify(arr, t, 0);
    }
    return arr;
}

int main()
{
    vector<int> arr = {3, 4, 1, 4, 5, 2, 1};
    printArr(arr);
    arr = heapSort(arr);
    printArr(arr);
    return 0;
}