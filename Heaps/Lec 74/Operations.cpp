#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Heap
{
public:
    vector<int> arr;
    int size;

    Heap()
    {
        size = 0;

        for (int i = 0; i < 10000; i++)
        {
            arr.push_back(0);
        }
        arr[0] = -1;
    }
    void insert(int val)
    {
        size++;
        int i = size;
        arr[i] = val;

        while (i > 1)
        {
            int parent = i / 2;
            if (arr[parent] < arr[i])
            {
                swap(arr[parent], arr[i]);
                i = parent;
            }
            else
            {
                return;
            }
        }
    }

    void print()
    {
        for (int i = 1; i <= size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    void deleteFromHeap()
    {
        if (size == 0)
        {
            cout << "Empty Heap";
            return;
        }

        arr[1] = arr[size--];

        int i = 1;
        while (i < size)
        {
            int leftIndex = 2 * i;
            int rightIndex = leftIndex + 1;

            if (leftIndex < size && arr[leftIndex] > arr[i])
            {
                swap(arr[leftIndex], arr[i]);
                i = leftIndex;
            }
            else if (rightIndex < size && arr[rightIndex] > arr[i])
            {
                swap(arr[rightIndex], arr[i]);
                i = rightIndex;
            }
            else
            {
                return;
            }
        }
    }
};

int main()
{
    Heap h;
    h.insert(50);
    h.insert(55);
    h.insert(52);
    h.insert(53);
    h.insert(54);
    h.print();
    h.deleteFromHeap();
    h.print();

    return 0;
}