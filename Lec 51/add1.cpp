#include "Node.cpp"

Node *reverse(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return NULL;
    }
    Node *prev = NULL, *curr = head;
    while (curr != NULL)
    {
        Node *fwd = curr->next;
        curr->next = prev;
        prev = curr;
        curr = fwd;
    }
    return prev;
}

void insert(Node *&tail, int d)
{
    Node *temp = new Node(d);
    tail->next = temp;
    tail = tail->next;
}

Node *addLL(Node *l1, Node *l2)
{
    int carry = 0;
    Node *anshead = new Node(-1);
    Node *anstail = anshead;
    while (carry != 0 || l1 != NULL || l1 != NULL)
    {
        int a = 0, b = 0;
        if (l1 != NULL)
        {
            a = l1->data;
        }
        if (l2 != NULL)
        {
            b = l2->data;
        }
        int sum = a + b + carry;
        int digit = sum % 10;
        insert(anstail, digit);
        carry = sum / 10;
        if (l1 != NULL)
        {
            l1 = l1->next;
        }
        if (l2 != NULL)
        {
            l2 = l2->next;
        }
    }
    return anshead->next;
}

Node *add1(Node *head)
{
    Node *l1 = head;
    Node *l2 = new Node(1);
    l1 = reverse(l1);
    Node *ans = addLL(l1, l2);
    ans = reverse(ans);
    return ans;
}
int main()
{
    Node *head = new Node(9);
    Node *node1 = new Node(9    );
    Node *node2 = new Node(9);
    Node *node3 = new Node(9);
    Node *node4 = new Node(9);
    Node *node5 = new Node(9);
    head->next = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    Node *ans = add1(head);
    print(ans);
    return 0;
}