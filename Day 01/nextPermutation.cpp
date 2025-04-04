#include <bits/stdc++.h>
#include <iostream>
using namespace std;

void reverse(vector<int> &arr, int s, int e)
{
    while (e > s)
    {
        swap(arr[s++], arr[e--]);
    }
}

void nextPermutation(vector<int> &nums)
{
    int index = -1;
    int n = nums.size();

    // step 1 finding index
    for (int i = n - 2; i >= 0; i--)
    {
        if (nums[i] < nums[i + 1])
        {
            index = i;
            break;
        }
    }
    if (index == -1)
    {
        reverse(nums, 0, n - 1);
        return;
    }
    // step 2
    for (int i = n - 1; i >= index; i--)
    {
        if (nums[index] < nums[i])
        {
            swap(nums[index], nums[i]);
            break;
        }
    }
    reverse(nums, index + 1, n - 1);
}

int main()
{
    vector<int> arr = {1, 2, 3, 4};
    nextPermutation(arr);
    for (auto i : arr)
    {
        cout << i << " ";
    }

    return 0;
}