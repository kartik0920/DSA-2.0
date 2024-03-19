#include "Node.cpp"

Node *getReverse(Node *head, int k)
{
    // base condition
    if (head == NULL)
    {
        return NULL;
    }

    // Changing 1 group
    int cnt = 0;
    Node *curr = head, *prev = NULL;
    Node *forward;
    while (curr != NULL && cnt < k)
    {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
        cnt++;
    }

    // recursvie call
    if (forward != NULL)
    {
        head->next = getReverse(forward, k);
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
    int k = 3;
    Node *ans = getReverse(head, k);
    print(head);
    print(ans);
    return 0;
}