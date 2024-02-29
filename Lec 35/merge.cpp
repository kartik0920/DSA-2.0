#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int> &arr, int s, int e)
{
    int mid = s + (e - s) / 2;
    int l1 = mid - s + 1;
    int l2 = e - mid;

    int *first = new int[l1];
    int *second = new int[l2];

    int k = s;
    for (int i = 0; i < l1; i++)
    {
        first[i] = arr[k++];
    }
    k = mid + 1;
    for (int i = 0; i < l2; i++)
    {
        second[i] = arr[k++];
    }

    int i = 0, j = 0;
    k = s;
    while (i < l1 && j < l2)
    {
        if (first[i] < second[j])
        {
            arr[k++] = first[i++];
        }
        else
        {
            arr[k++] = second[j++];
        }
    }

    while (i < l1)
    {
        arr[k++] = first[i++];
    }
    while (j < l2)
    {
        arr[k++] = second[j++];
    }

    delete[] first;
    delete[] second;
}
void Mergesort(vector<int> &arr, int s, int e)
{
    if (s >= e)
    {
        return;
    }
    int mid = s + (e - s) / 2;
    Mergesort(arr, s, mid);
    Mergesort(arr, mid + 1, e);

    merge(arr, s, e);
}
int main()
{
    vector<int> arr = {7, 2, 5, 0, 3, 2};
    Mergesort(arr, 0, arr.size() - 1);
    for (int i = 0; i < arr.size(); i++)
    {
        cout << ' ' << arr[i];
    }
    cout << endl;
    return 0;
}