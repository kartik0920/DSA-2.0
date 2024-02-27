#include <iostream>
#include <vector>
using namespace std;

bool search(vector<int> arr)
{
    int count = 0;
    for (int i = 1; i < arr.size(); i++)
    {
        if (arr[i - 1] > arr[i])
        {
            count += 1;
        }
    }
    if (arr[0] < arr[arr.size() - 1])
    {
        count++;
    }
    if (count > 1)
    {
        return 0;
    }
    return 1;
}
int main()
{
    vector<int> arr = {
        3,
        4,
        5,
        1,
        7,
    };
    bool good = search(arr);
    if (good)
    {
        cout << "array is sorted and rotated" << endl;
    }
    else
    {
        cout << "<3" << endl;
    }
    return 0;
}