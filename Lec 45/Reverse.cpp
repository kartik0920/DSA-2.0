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

Node *reverse1(Node *&head)
{
    Node *prev = NULL, *curr = head;
    while (curr != NULL)
    {
        Node *temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    return prev;
}

void solve(Node *&head, Node *curr, Node *prev)
{
    if (curr == NULL)
    {
        head = prev;
        return;
    }
    solve(head, curr->next, curr);
    curr->next = prev;
}

Node *reverse2(Node *&head)
{
    Node *prev = NULL, *curr = head;
    solve(head, curr, prev);
    return head;
}

Node *reverse3(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    Node *small = reverse3(head->next);
    head->next->next = head;
    head->next = NULL;
    return small;
}
int main()
{
    Node *head = new Node(0);
    Node *node1 = new Node(10);
    Node *node2 = new Node(20);
    Node *node3 = new Node(30);
    Node *node4 = new Node(40);
    Node *node5 = new Node(50);
    head->next = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;

    // Node *r1 = reverse1(head);
    // print(r1);

    // Node *r2 = reverse2(head);
    // print(r2);

    Node *r3 = reverse3(head);
    print(r3);

    return 0;
}