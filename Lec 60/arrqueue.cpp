#include <bits/stdc++.h>
#include <iostream>
using namespace std;
class MyQueue
{
private:
    int *arr;
    int size, front, rear;

public:
    MyQueue(int n)
    {
        this->size = n;
        arr = new int[size];
        front = 0;
        rear = 0;
    }
    void push(int x)
    {
        if (rear == size)
        {
            cout << "It is overflow" << endl;
            return;
        }
        else
        {
            arr[++rear] = x;
        }
    }
    void pop()
    {
        if (rear == front)
        {
            cout << "It is underflown" << endl;
        }
        else
        {
            arr[front] = -1;
            front++;
            if (front == rear)
            {
                front = rear = 0;
            }
        }
    }
    bool IsEmpty()
    {
        return rear == front ? 1 : 0;
    }
    int queuesize()
    {
        return rear - front;
    }
};
int main()
{
    MyQueue q(5);
    cout << q.IsEmpty() << endl;
    q.push(12);
    q.push(12);
    q.push(12);
    q.push(12);
    q.push(12);
    q.push(12);
    return 0;
}