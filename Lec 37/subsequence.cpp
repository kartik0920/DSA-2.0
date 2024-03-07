#include <iostream>
#include <vector>
using namespace std;
void printArr(vector<string> ans)
{
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << ' ';
    }
    cout << endl;
}

void solve(string str, string output, int index, vector<string> &ans)
{
    if (index >= str.length())
    {
        if (output.length() >= 1)
        {
            ans.push_back(output);
        }
        return;
    }
    solve(str, output, index + 1, ans);
    char ch = str[index];
    output.push_back(ch);
    solve(str, output, index + 1, ans);
}

vector<string>
GetSub(string str)
{
    vector<string> ans;
    string output = "";
    int index = 0;
    solve(str, output, index, ans);
    return ans;
}
int main()
{
    string str = "abc";
    vector<string> ans = GetSub(str);
    printArr(ans);
    return 0;
}