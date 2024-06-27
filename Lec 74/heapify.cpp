#include <bits/stdc++.h>
#include <iostream>
using namespace std;
void printArr(vector<int> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << ' ';
    }
}

void heapify(vector<int> &arr, int n, int i)
{
    int smallest = i;
    int left = i * 2 + 1;
    int right = left + 1;

    if (left < n && arr[smallest] > arr[left])
    {
        smallest = left;
    }
    if (right < n && arr[smallest] > arr[right])
    {
        smallest = right;
    }

    if (smallest != i)
    {
        swap(arr[smallest], arr[i]);
        heapify(arr, n, smallest);
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
int main()
{
    vector<int> arr = {55, 56, 74, 26, 105};
    BuildHeap(arr);

    printArr(arr);
    cout << endl;
    return 0;
}