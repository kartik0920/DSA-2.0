#include "Node.cpp"

int GetLen(Node *head)
{
    int cnt = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        temp = temp->next;
        cnt++;
    }
    return cnt;
}
Node *GetMiddle1(Node *head)
{
    int len = GetLen(head);
    int ans = len / 2;
    int cnt = 0;
    Node *temp = head;
    while (cnt < ans)
    {
        cnt++;
        temp = temp->next;
    }
    return temp;
}
Node *GetMiddle2(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    Node *slow = head, *fast = head->next;
    while (fast != NULL)
    {
        slow = slow->next;
        fast = fast->next;
        if (fast != NULL)
        {
            fast = fast->next;
        }
    }
    return slow;
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

    // Node *m1 = GetMiddle1(head);
    // print(m1);

    Node *m2 = GetMiddle2(head);
    print(m2);
    return 0;
}