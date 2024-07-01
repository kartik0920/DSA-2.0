#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int MaxFreq(vector<int> arr)
{
    int ans = -1;
    int Max_freq = INT_MIN;
    unordered_map<int, int> m;
    for (int i = 0; i < arr.size(); i++)
    {
        m[arr[i]]++;
        if (m[arr[i]] > Max_freq)
        {
            ans = arr[i];
            Max_freq = m[arr[i]];
        }
    }
    return ans;
}
int main()
{
    vector<int> arr = {1, 2, 2, 3, 4, 5, 5};
    cout << "Maximum Frequency is of " << MaxFreq(arr) << endl;

    return 0;
}