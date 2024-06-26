#include <bits/stdc++.h>
#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};
void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << ' ';
        temp = temp->next;
    }
    cout << endl;
}

int GetLen(Node *head)
{
    int cnt = 0;
    while (head != NULL)
    {
        cnt++;
        head = head->next;
    }
    return cnt;
}

Node *GetMiddle1(Node *head)
{
    int len = GetLen(head);
    int ans = len / 2;
    int cnt = 0;
    Node *temp = head;
    while (cnt < ans)
    {
        temp = temp->next;
        cnt++;
    }
    return temp;
}

Node *GetMiddle2(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    Node *slow = head, *fast = head->next;
    while (fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            fast = fast->next;
        }
        slow = slow->next;
    }
    return slow;
}

int main()
{
    Node *head = new Node(0);
    Node *node1 = new Node(10);
    Node *node2 = new Node(20);
    Node *node3 = new Node(30);
    Node *node4 = new Node(40);
    // Node *node5 = new Node(50);
    head->next = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    // node4->next = node5;
    Node *middle1 = GetMiddle1(head);
    Node *middle2 = GetMiddle2(head);
    print(head);
    print(middle1);
    print(middle2);
    return 0;
}