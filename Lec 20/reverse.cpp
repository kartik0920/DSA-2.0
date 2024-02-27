#include <iostream>
#include <vector>
using namespace std;

void printArr(vector<int> arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << ' ';
    }
    cout << endl;
}

void reverse(vector<int> &arr)
{
    int s = 0, e = arr.size() - 1;
    while (s <= e)
    {
        swap(arr[s++], arr[e--]);
    }
}

void reverse(vector<int> &arr, int k)
{
    int s = k, e = arr.size() - 1;
    while (s <= e)
    {
        swap(arr[s++], arr[e--]);
    }
}

int main()
{
    vector<int> arr = {4, 3, 1, 0};
    printArr(arr);
    cout << "After reverse\n";
    reverse(arr, 1);
    printArr(arr);
    return 0;
}