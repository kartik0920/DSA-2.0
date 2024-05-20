#include "Node.cpp"

Node *sort01_1(Node *head)
{
    int zcnt = 0, ocnt = 0, tcnt = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == 0)
        {
            zcnt++;
        }
        else if (temp->data == 1)
        {
            ocnt++;
        }
        else
        {
            tcnt++;
        }
        temp = temp->next;
    }
    temp = head;
    while (temp != NULL)
    {
        if (zcnt != 0)
        {
            zcnt--;
            temp->data = 0;
        }
        else if (ocnt != 0)
        {
            ocnt--;
            temp->data = 1;
        }
        else
        {
            tcnt--;
            temp->data = 2;
        }
        temp = temp->next;
    }
    return head;
}

Node *sort01_2(Node *head)
{
    Node *zerohead = new Node(-1);
    Node *onehead = new Node(-1);
    Node *twohead = new Node(-1);
    Node *onetail = onehead, *zerotail = zerohead, *twotail = twohead;
    Node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == 0)
        {
            zerotail->next = temp;
            zerotail = zerotail->next;
            // zerotail->next = NULL;
        }
        else if (temp->data == 1)
        {
            onetail->next = temp;
            onetail = onetail->next;
            // onetail->next = NULL;
        }
        else
        {
            twotail->next = temp;
            twotail = twotail->next;
            // twotail->next = NULL;
        }
        temp = temp->next;
    }
    onetail->next = twohead->next;
    if (onehead->next != NULL)
    {
        zerotail->next = onehead->next;
    }
    else
    {
        zerotail->next = twohead->next;
    }
    return zerohead->next;
}
int main()
{
    Node *head = new Node(1);
    Node *node1 = new Node(0);
    Node *node2 = new Node(0);
    Node *node3 = new Node(1);
    Node *node4 = new Node(1);
    Node *node5 = new Node(0);
    head->next = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    print(head);
    // Node *ans = sort01_1(head);
    Node *ans = sort01_2(head);
    print(ans);
    return 0;
}