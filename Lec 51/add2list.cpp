#include "Node.cpp"

Node *reverse(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
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

void insert(Node *&tail, int digit)
{
    Node *temp = new Node(digit);
    tail->next = temp;
    tail = tail->next;
}

Node *add(Node *first, Node *second)
{
    Node *anshead = new Node(-1);
    Node *anstail = anshead;
    int carry = 0;
    while (first != NULL || second != NULL || carry != 0)
    {
        int a = 0, b = 0;
        if (first != NULL)
        {
            a = first->data;
        }
        if (second != NULL)
        {
            b = second->data;
        }
        int sum = a + b + carry;
        int digit = sum % 10;
        insert(anstail, digit);
        carry = sum / 10;
        if (first != NULL)
        {
            first = first->next;
        }
        if (second != NULL)
        {
            second = second->next;
        }
    }
    return anshead->next;
}
struct Node *addTwoLists(struct Node *num1, struct Node *num2)
{
    num1 = reverse(num1);
    num2 = reverse(num2);
    Node *ans = add(num1, num2);
    ans = reverse(ans);
    return ans;
}
int main()
{
    Node *head1 = new Node(0);
    Node *node1 = new Node(1);
    Node *node2 = new Node(2);
    Node *node3 = new Node(3);
    Node *node4 = new Node(4);
    Node *node5 = new Node(5);
    head1->next = node1;
    node1->next = node2;
    node2->next = NULL;
    Node *head2 = node3;
    node3->next = node4;
    node4->next = node5;
    print(head1);
    print(head2);
    Node *sum = addTwoLists(head1, head2);
    print(sum);
    return 0;
}