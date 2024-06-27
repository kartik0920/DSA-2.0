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
    if (left < n && arr[left] > arr[largest])
    {
        largest = left;
    }
    if (right < n && arr[right] > arr[largest])
    {
        largest = right;
    }

    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

vector<int> MergeHeap(vector<int> arr1, vector<int> arr2)
{
    vector<int> ans = arr1;
    for (int i = 0; i < arr2.size(); i++)
    {
        ans.push_back(arr2[i]);
    }
    int n = ans.size();

    for (int i = (n / 2) - 1; i >= 0; i--)
    {
        heapify(ans, n, i);
    }
    return ans;
}
int main()
{
    vector<int> arr1 = {5, 4, 3};
    vector<int> arr2 = {8, 5, 7, 4, 2};

    vector<int> arr3 = MergeHeap(arr1, arr2);
    cout << "!" << endl;
    printArr(arr3);
    return 0;
}