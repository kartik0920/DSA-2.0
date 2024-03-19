#include "Node.cpp"

Node *getMiddle(Node *head)
{
    Node *temp = head;
    int len = 0;
    while (temp != NULL)
    {
        len++;
        temp = temp->next;
    }
    int cnt = 0;
    temp = head;
    while (cnt < (len / 2))
    {
        temp = temp->next;
        cnt++;
    }
    return temp;
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
    Node *middle = getMiddle(head);
    print(middle);
    return 0;
}