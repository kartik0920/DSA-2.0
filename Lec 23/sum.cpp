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

void sumodrow(vector<vector<int>> arr)
{
    vector<int> ans;
    for (int i = 0; i < arr.size(); i++)
    {
        vector<int> temp = arr[i];
        int sum = 0;
        for (int j = 0; j < temp.size(); j++)
        {
            sum += temp[j];
        }
        ans.push_back(sum);
    }
    printArr(ans);
}
int main()
{
    vector<vector<int>> arr = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    printArr(arr);
    sumodrow(arr);
    return 0;
}