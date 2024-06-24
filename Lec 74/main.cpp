#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Heap
{
public:
    int s;
    int size;
    int *arr;

    Heap(int s)
    {
        this->s = s;
        this->arr = new int[s];
        this->size = 0;
    }

    void print()
    {
        cout << "Here is headp" << endl;
        for (int i = 1; i <= size; i++)
        {
            cout << arr[i] << ' ';
        }
        cout << endl;
    }
    void insert(int d)
    {
        size++;
        int index = size;
        arr[index] = d;

        while (index > 1)
        {
            int ParentIndex = index / 2;
            if (arr[ParentIndex] < arr[index])
            {
                swap(arr[ParentIndex], arr[index]);
                index = ParentIndex;
            }
            else
            {
                return;
            }
        }
    }

    void deleteVal()
    {
        if (size == 0)
        {
            cout << "Empty Heap" << endl;
            return;
        }
        arr[1] = arr[size--];
        int index = 1;
        while (index < size)
        {
            int leftchild = index * 2;
            int rightchild = leftchild + 1;

            if (leftchild < size && arr[leftchild] > arr[index])
            {
                swap(arr[leftchild], arr[index]);
                index = leftchild;
            }
            else if (rightchild < size && arr[rightchild] > arr[index])
            {
                swap(arr[rightchild], arr[index]);
                index = rightchild;
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
    Heap h(100);
    h.insert(50);
    h.print();
    h.insert(60);
    h.insert(30);
    h.insert(20);
    h.insert(40);
    h.print();
    h.deleteVal();
    h.deleteVal();
    h.print();
    return 0;
}