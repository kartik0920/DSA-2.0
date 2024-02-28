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

void printArr(vector<vector<int>> arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        vector<int> temp = arr[i];
        printArr(temp);
    }
    cout << endl;
}

bool search(vector<vector<int>> arr, int key)
{
    for (int i = 0; i < arr.size(); i++)
    {
        vector<int> temp = arr[i];
        for (int j = 0; j < temp.size(); j++)
        {
            if (temp[j] == key)
            {
                return 1;
            }
        }
    }
    return 0;
}
int main()
{
    vector<vector<int>> arr = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    printArr(arr);

    int key = 6;
    bool found = search(arr, key);
    if (found)
    {
        cout << "Key is present" << endl;
    }
    else
    {
        cout << "Key is absent" << endl;
    }
    return 0;
}