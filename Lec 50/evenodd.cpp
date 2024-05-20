#include "Node.cpp"
void rearrangeEvenOdd(Node *head)
{
    Node *oddhead = new Node(-1), *evenhead = new Node(-1);
    Node *oddtail = oddhead, *eventail = evenhead;
    Node *temp = head;
    while (temp != NULL)
    {
        if ((temp->data % 2) != 0)
        {
            oddtail->next = temp;
            oddtail = oddtail->next;
            temp = temp->next;
            oddtail->next = NULL;
        }
        else
        {
            eventail->next = temp;
            eventail = eventail->next;
            temp = temp->next;
            eventail->next = NULL;
        }
    }

    if (oddhead->next == NULL)
    {
        head = evenhead->next;
    }
    oddtail->next = evenhead->next;
    head = oddhead->next;
}
int main()
{
    Node *head = new Node(01);
    Node *node1 = new Node(1101);
    Node *node2 = new Node(2101);
    Node *node3 = new Node(321);
    Node *node4 = new Node(41);
    Node *node5 = new Node(5101);
    head->next = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    rearrangeEvenOdd(head);
    print(head);
    return 0;
}