#include <bits/stdc++.h>
#include <iostream>
using namespace std;
class Stack
{
private:
    int *arr;
    int size, top;

public:
    Stack(int size)
    {
        this->size = size;
        this->top = -1;
        arr = new int[size];
    }
    void push(int x);
    void pop();
    bool empty();
    int peek();
};
void Stack::push(int x)
{
    if ((size - top) > 1)
    {
        top++;
        arr[top] = x;
    }
    else
    {
        cout << "Stack is overflown" << endl;
    }
}

void Stack::pop()
{
    if (top == -1)
    {
        cout << "Stack is undeflow" << endl;
    }
    else
    {
        cout << "This element was deleted ::" << arr[top] << endl;
        top--;
    }
}

bool Stack::empty()
{
    return top == -1 ? 1 : 0;
}

int Stack::peek()
{
    if (top == -1)
    {
        cout << "Stack is empty";
        return -1;
    }
    else
    {
        return arr[top];
    }
}

int main()
{
    Stack s(2);
    cout << s.empty() << endl;
    s.push(1);
    cout << s.empty() << endl;
    s.push(2);
    s.push(3);
    s.pop();
    cout << s.peek() << endl;
    s.pop();
    cout << s.peek() << endl;
    s.pop();
    cout << s.peek() << endl;
    s.pop();
    cout << s.peek() << endl;
    s.pop();
    cout << s.peek() << endl;
    return 0;
}