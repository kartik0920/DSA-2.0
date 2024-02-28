#include <iostream>
using namespace std;

int getMax(int *arr, int size)
{
    int max = arr[0];
    int index = 0;
    for (int i = 0; i < size; i++)
    {
        if (max < arr[i])
        {
            max = arr[i];
            index = i;
        }
    }
    return index;
}
char getMaxChar(string str)
{
    int Map[26] = {0};
    for (int i = 0; i < str.length(); i++)
    {
        char ch = str[i];
        if (ch >= 'A' && ch <= 'Z')
        {
            int index = ch - 'A';
            Map[index]++;
        }
        else
        {
            int index = ch - 'a';
            Map[index]++;
        }
    }
    int maxIndex = getMax(Map, 26);
    return maxIndex + 'a';
}
int main()
{
    string s;
    cout << "Enter string:";
    cin >> s;
    cout << "Maximum letter is " << getMaxChar(s) << endl;
    return 0;
}