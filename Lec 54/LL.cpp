#include <bits/stdc++.h>
#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int d)
    {
        this->data = d;
        this->next = NULL;
    }
};
class Stack
{
public:
    Node *head;
    Node *tail;
    void push(int x);
    void pop();
    int peek();
    bool empty();
    Stack()
    {
        this->head = NULL;
        tail = head;
    }
};
void Stack::push(int x)
{
    if (head == NULL)
    {
        Node *insert = new Node(x);
        head = insert;
        tail = head;
    }
    else
    {
        Node *insert = new Node(x);
        tail->next = insert;
        tail = insert;
    }
}
int Stack::peek()
{
    if (tail == NULL)
    {
        cout << "It is empty" << endl;
        return -1;
    }
    else
    {
        return tail->data;
    }
}
bool Stack::empty()
{
    return tail == NULL ? 0 : 1;
}
void Stack::pop()
{
    if (tail == NULL)
    {
        cout << "Stack underflown" << endl;
    }
    else if (head->next == NULL)
    {
        head = NULL;
        tail = NULL;
    }
    else
    {
        Node *temp = head;
        while (temp->next != tail)
        {
            temp = temp->next;
        }
        tail = temp;
        temp->next = NULL;
    }
}

int main()
{
    Stack S;
    S.push(12);
    S.push(13);
    S.push(13);
    S.pop();
    S.pop();
    S.pop();
    cout << S.peek() << endl;
    return 0;
}