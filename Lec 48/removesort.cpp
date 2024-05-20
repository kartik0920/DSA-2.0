#include "Node.cpp"
Node *remove(Node *head)
{
    if (head == NULL)
    {
        return NULL;
    }
    Node *curr = head;
    while (curr != NULL)
    {
        if ((curr->next != NULL) && (curr->data == curr->next->data))
        {
            Node *temp = curr->next;
            curr->next = temp->next;
            temp->next = NULL;
            delete temp;
        }
        else
        {
            curr = curr->next;
        }
    }
    return head;
}

int main()
{
    Node *head = new Node(0);
    Node *node1 = new Node(10);
    Node *node2 = new Node(10);
    Node *node3 = new Node(30);
    Node *node4 = new Node(30);
    Node *node5 = new Node(50);
    head->next = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    Node *ans = remove(head);
    print(ans);
    return 0;
}