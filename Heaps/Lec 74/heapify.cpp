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
    int largerst = i;
    int left = 2 * i;
    int right = left + 1;

    if (left < n && arr[largerst] < arr[left])
    {
        largerst = left;
    }
    if (right < n && arr[largerst] < arr[right])
    {
        largerst = right;
    }

    if (largerst != i)
    {
        swap(arr[largerst], arr[i]);
        heapify(arr, n, largerst);
    }
}

int main()
{
    vector<int> arr = {-1, 54, 53, 55, 52, 50};
    int n = arr.size() - 1;
    for (int i = n / 2; i > 0; i--)
    {
        heapify(arr, n, i);
    }

    printArr(arr);
    return 0;
}