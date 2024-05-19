#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = NULL;
        this->next = NULL;
    }
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
    Node(int data, Node *add)
    {
        this->data = data;
        this->next = add;
    }
    ~Node()
    {
        if (this->next != NULL)
        {
            delete next;
            this->next = NULL;
        }
    }
};
void printLL(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
void insertHead(Node *&head, Node *&tail, int data)
{
    if (head == NULL)
    {
        Node *temp = new Node(data);
        head = temp;
        tail = temp;
        return;
    }
    else
    {
        Node *temp = new Node(data);
        temp->next = head;
        head = temp;
    }
}
void insertTail(Node *&head, Node *&tail, int data)
{
    if (tail == NULL)
    {
        insertHead(head, tail, data);
    }
    else
    {
        Node *temp = new Node(data);
        tail->next = temp;
        tail = temp;
    }
}
void insertPosi(Node *&head, Node *&tail, int data, int posi)
{
    if (posi == 1)
    {
        insertHead(head, tail, data);
        return;
    }
    int cnt = 1;
    Node *temp = head;
    while (cnt < posi - 1)
    {
        cnt++;
        if (temp == NULL)
        {
            cout << "Lenght of LL is less insert corrrect position" << endl;
            return;
        }
        temp = temp->next;
    }
    if (temp->next == NULL)
    {
        insertTail(head, tail, data);
        return;
    }
    Node *toinsert = new Node(data);
    toinsert->next = temp->next;
    temp->next = toinsert;
}
void deletePosi(Node *&head, Node *&tail, int posi)
{
    if (posi == 1)
    {
        Node *temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }
    else
    {
        Node *prev = NULL, *curr = head;
        int cnt = 1;
        while (cnt < posi)
        {
            cnt++;
            prev = curr;
            curr = curr->next;
        }
        prev->next = curr->next;

        if (curr->next == NULL)
        {
            tail = prev;
        }
        curr->next = NULL;
        delete curr;
    }
}
void deleteVal(Node *&head, Node *&tail, int val)
{
    if (head->data == val)
    {
        Node *temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }
    else
    {
        Node *prev = NULL, *curr = head;
        while (curr->data != val)
        {
            if (curr->next == NULL)
            {
                cout << "No such element" << endl;
                return;
            }
            prev = curr;
            curr = curr->next;
        }
        if (tail->data == val)
        {
            tail = prev;
            tail->next = NULL;
            delete curr;
            return;
        }
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
}
bool search(Node *head, int val)
{
    Node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == val)
        {
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}
int main()
{
    Node *head = NULL;
    Node *tail = NULL;
    insertHead(head, tail, 1);
    insertHead(head, tail, 0);
    insertTail(head, tail, 2);
    insertTail(head, tail, 3);
    insertPosi(head, tail, 4, 5);
    deleteVal(head, tail, 56);
    cout << "Head ::::::" << head->data << endl;
    cout << "tail ::::::" << tail->data << endl;
    printLL(head);
    cout << search(head,     5) << endl;
    return 0;
}