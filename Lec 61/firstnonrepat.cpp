#include <bits/stdc++.h>
#include <iostream>
using namespace std;
string FirstNonRepeating(string A)
{
    unordered_map<char, int> mapping;
    queue<char> q;
    string ans = "";
    for (int i = 0; i < A.length(); i++)
    {
        char ch = A[i];
        mapping[ch]++;
        q.push(ch);

        while (!q.empty())
        {
            if (mapping[q.front()] > 1)
            {
                q.pop();
            }
            else
            {
                ans.push_back(q.front());
                break;
            }
        }
        if (q.empty())
        {
            ans.push_back('#');
        }
    }
    return ans;
}
int main()
{
    string A = "Kartik";
    cout << FirstNonRepeating(A) << endl;
    return 0;
}