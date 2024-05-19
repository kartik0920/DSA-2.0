#include "Node.cpp"

Node *reverseK(Node *&head, int k)
{
    if (head == NULL)
    {
        return NULL;
    }
    Node *prev = NULL, *curr = head, *forward;
    int cnt = 0;
    while (cnt < k && curr != NULL)
    {
        cnt++;
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }

    if (forward != NULL && cnt == k)
    {
        head->next = reverseK(forward, k);
    }
    return prev;
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
    print(head);
    int k = 4;
    Node *r2 = reverseK(head, k);
    print(r2);
    return 0;
}