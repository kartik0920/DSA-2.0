#include <bits/stdc++.h>
#include <iostream>
using namespace std;

string LongPre(vector<string> arr, int n)
{
    string first = arr[0];
    string ans = "";
    for (int i = 0; i < first.length(); i++)
    {
        char ch = first[i];
        bool match = 1;
        for (int j = 1; j < n; j++)
        {
            if (arr[j].size() < i || arr[j][i] != ch)
            {
                match = 0;
                break;
            }
        }
        if (!match)
        {
            return ans;
        }
        else
        {
            ans.push_back(ch);
        }
    }
    return ans;
}
int main()
{
    vector<string> arr = {
        "coding",
        "codir",
        "codingninja"};
    int n = arr.size();
    cout << LongPre(arr, n) << endl;
    return 0;
}