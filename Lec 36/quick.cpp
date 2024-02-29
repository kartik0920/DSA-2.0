#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int> &arr, int s, int e)
{
    int pivot = arr[s];

    int cnt = 0;
    for (int i = s + 1; i <= e; i++)
    {

        if (pivot > arr[i])
        {
            cnt++;
        }
    }
    int pivot_index = s + cnt;
    swap(arr[pivot_index], arr[s]);

    int i = s, j = e;
    while (i < pivot_index && j > pivot_index)
    {
        while (arr[i] < pivot)
        {
            i++;
        }
        while (arr[j] > pivot)
        {
            j--;
        }
        if (i < pivot_index && j > pivot_index)
        {
            swap(arr[i], arr[j]);
        }
    }
    return pivot_index;
}
void QuickSort(vector<int> &arr, int s, int e)
{
    if (s >= e)
    {
        return;
    }

    int p = partition(arr, s, e);

    QuickSort(arr, s, p - 1);
    QuickSort(arr, p + 1, e);
}
int main()
{
    vector<int> arr = {7, 2, 5, 0, 3, 2};
    QuickSort(arr, 0, arr.size() - 1);
    for (int i = 0; i < arr.size(); i++)
    {
        cout << ' ' << arr[i];
    }
    cout << endl;
    return 0;
}