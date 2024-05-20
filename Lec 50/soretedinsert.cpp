#include "Node.cpp"
Node *sortedInsert(struct Node *head, int data)
{
    if (head->data >= data)
    {
        Node *insert = new Node(data);
        insert->next = head;
        head = insert;
        return head;
    }
    Node *curr = head->next, *prev = head;

    while (curr->next != head)
    {
        if ((curr->data >= data) && (prev->data <= data))
        {
            Node *insert = new Node(data);
            prev->next = insert;
            insert->next = curr;
            break;
        }
        curr = curr->next;
        prev = prev->next;
    }
    if (prev->next == NULL)
    {
        Node *insert = new Node(data);
        prev->next = insert;
        insert->next = head;
    }
    return head;
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
    node5->next = head;
    Node *a = sortedInsert(head, 115);
    print(a);
    return 0;
}