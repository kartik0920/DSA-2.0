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

void h2(vector<int> &arr, int i, int n)
{
    int largest = i;
    int leftchild = i * 2 + 1;
    int rightchild = leftchild + 1;

    if (leftchild < n && arr[largest] < arr[leftchild])
    {
        largest = leftchild;
    }
    if (rightchild < n && arr[largest] < arr[rightchild])
    {
        largest = rightchild;
    }

    if (largest != i)
    {
        swap(arr[largest], arr[i]);
        h2(arr, largest, n);
    }
}

void solve(vector<int> &arr)
{
    int n = arr.size();

    for (int i = (n / 2) - 1; i >= 0; i--)
    {
        h2(arr, i, n - 1);
    }
}

void HeapSort(vector<int> &arr, int size)
{
    solve(arr);

    for (int i = size - 1; i >= 0; i--)
    {
        swap(arr[i], arr[0]);
        h2(arr, 0, i);
    }
}

int main()
{
    vector<int> arr = {6, 5, 4, 3, 2, 1};

    solve(arr);
    printArr(arr);

    HeapSort(arr, arr.size());
    printArr(arr);
}