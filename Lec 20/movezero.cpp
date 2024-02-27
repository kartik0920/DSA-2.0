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

void movezero(vector<int> &arr)
{
    int non_zero = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] != 0)
        {
            swap(arr[non_zero], arr[i]);
            non_zero++;
        }
    }
}
int main()
{
    vector<int> arr = {2, 3, 0, 1, 0, 4, 1, 0};
    movezero(arr);
    printArr(arr);
    return 0;
}