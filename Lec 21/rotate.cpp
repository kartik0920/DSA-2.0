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

void rotate(vector<int> &arr, int k)
{
    vector<int> temp = arr;
    int size = arr.size();
    for (int i = 0; i < arr.size(); i++)
    {
        arr[(i + k) % size] = temp[i];
    }
}
int main()
{
    vector<int> arr = {1, 7, 9, 11};
    int k = 3;
    rotate(arr, k);
    printArr(arr);
    return 0;
}