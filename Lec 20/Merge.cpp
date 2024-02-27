#include <iostream>
#include <vector>
using namespace std;

vector<int> merge(vector<int> arr1, vector<int> arr2)
{
    int m = arr1.size(), n = arr2.size();
    vector<int> ans;
    // cout << ans.size();
    int i = 0, k = 0, j = 0;
    while (i < m && j < n)
    {
        // i++;
        if (arr1[i] < arr2[j])
        {
            ans.push_back(arr1[i++]);
        }
        else
        {
            ans.push_back(arr2[j++]);
        }
    }
    while (i < m)
    {
        ans.push_back(arr1[i++]);
    }
    while (j < n)
    {
        ans.push_back(arr2[j++]);
    }
    return ans;
}

void printArr(vector<int> arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << ' ';
    }
    cout << endl;
}
int main()
{
    vector<int> arr1 = {1, 2, 3, 4};
    vector<int> arr2 = {2, 6, 8};
    vector<int> arr3 = merge(arr1, arr2);
    printArr(arr3);
    return 0;
}