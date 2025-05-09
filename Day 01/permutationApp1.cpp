#include <bits/stdc++.h>
#include <iostream>
using namespace std;

void temp(vector<int> arr, int n, vector<bool> &visited, vector<vector<int>> &ans, vector<int> &tempArr)
{

    if (tempArr.size() == n)
    {
        ans.push_back(tempArr);
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            visited[i] = 1;
            tempArr.push_back(arr[i]);
            temp(arr, n, visited, ans, tempArr);
            tempArr.pop_back();
            visited[i] = 0;
        }
    }
}

vector<vector<int>> solve(vector<int> arr)
{
    int n = arr.size();
    vector<vector<int>> ans;
    vector<bool> visited(n, 0);
    vector<int> tempArr;
    // int index = 0;
    temp(arr, n, visited, ans, tempArr);

    return ans;
}
int main()
{
    vector<int> arr = {1, 2, 3};

    vector<vector<int>> ans = solve(arr);
    for (auto i : ans)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}