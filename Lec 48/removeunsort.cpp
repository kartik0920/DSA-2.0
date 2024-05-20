#include "Node.cpp"

Node *remove(Node *head)
{
    if (head == NULL)
    {
        return NULL;
    }
    unordered_map<int, bool> mapping;
    Node *curr = head, *prev = NULL;
    while (curr != NULL)
    {
        if (!mapping[curr->data])
        {
            mapping[curr->data] = 1;
            prev = curr;
            curr = curr->next;
        }
        else
        {
            curr = curr->next;
            prev->next->next = NULL;
            delete prev->next;
            prev->next = curr;
        }
    }
    return head;
}
int main()
{
    Node *head = new Node(0);
    Node *node1 = new Node(10);
    Node *node2 = new Node(0);
    Node *node3 = new Node(30);
    Node *node4 = new Node(30);
    Node *node5 = new Node(0);
    head->next = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    Node *ans = remove(head);
    cout << endl;
    print(ans);
    return 0;
}