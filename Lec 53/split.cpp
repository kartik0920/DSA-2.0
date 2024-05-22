#include "Node.cpp"
Node *getMid(Node *head)
{
    Node *slow = head, *fast = head->next;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

void splitList(Node *head, Node *&head1_ref, Node *&head2_ref)
{

    Node *temp = head->next;
    while (temp->next != head)
    {
        temp = temp->next;
    }
    temp->next = NULL;
    Node *mid = getMid(head);

    Node *l = head;
    Node *k = mid->next;
    mid->next = l;

    temp = k;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = k;
    head1_ref = l;
    head2_ref = k;
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
    Node *left = NULL, *right = NULL;
    splitList(head, left, right);
    print(left);
    print(right);
    return 0;
}