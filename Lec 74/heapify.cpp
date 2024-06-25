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

    for (int i = n / 2; i > 0; i--)
    {
        h2(arr, i, n);
    }
}

int main()
{
    vector<int> arr = {12, 3, 5, 1, 5, 6};

    solve(arr);
    printArr(arr);
}