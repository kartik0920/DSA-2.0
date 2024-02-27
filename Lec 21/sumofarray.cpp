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
    while (e >= s)
    {
        swap(arr[s++], arr[e--]);
    }
}
vector<int> add(vector<int> arr1, vector<int> arr2)
{
    vector<int> ans;
    int carry = 0;
    int m = arr1.size(), n = arr2.size();
    int i = m - 1, j = n - 1;
    while (i >= 0 && j >= 0)
    {
        int val1 = arr1[i];
        int val2 = arr2[j];
        int sum = val1 + val2 + carry;
        carry = sum / 10;
        ans.push_back(sum % 10);
        i--;
        j--;
    }
    while (i >= 0 || carry != 0)
    {
        int val1 = arr1[i];
        int sum = val1 + carry;
        carry = sum / 10;
        ans.push_back(sum % 10);
        i--;
    }
    while (j >= 0 || carry != 0)
    {
        int val1 = arr2[j];
        int sum = val1 + carry;
        carry = sum / 10;
        ans.push_back(sum % 10);
        j--;
    }
    reverse(ans);
    return ans;
}
int main()
{
    vector<int> arr1 = {1, 2, 3};
    vector<int> arr2 = {1, 0, 0};
    vector<int> sum = add(arr1, arr2);
    printArr(sum);
    return 0;
}