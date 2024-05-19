#include "Node.cpp"
Node *DetectLoop(Node *head)
{
    if (head == NULL)
    {
        return NULL;
    }
    Node *slow = head, *fast = head;
    while (slow != NULL && fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            fast = fast->next;
        }
        slow = slow->next;
        if (slow == fast)
        {
            return slow;
        }
    }
    return NULL;
}
Node *start(Node *head)
{
    Node *fast = DetectLoop(head);
    if (fast == NULL)
    {
        return NULL;
    }
    Node *slow = head;
    while (slow != fast)
    {
        slow = slow->next;
        fast = fast->next;
    }
    cout << "Start is at " << slow->data << endl;
    return slow;
}
void removeloop(Node *head)
{
    Node *s = start(head);
    if (s == NULL)
    {
        return;
    }
    Node *temp = start(head);
    temp = temp->next;
    while (temp->next != s)
    {
        temp = temp->next;
    }
    cout << "temp" << temp->data << endl;
    temp->next = NULL;
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
    node5->next = node2;
    Node *n1 = DetectLoop(head);
    if (n1 == NULL)
    {
        cout << "Loop is absent" << endl;
    }
    else
    {
        cout << "Loop is present" << endl;
    }
    Node *s = start(head);
    // print(head);
    // remove of loop
    removeloop(head);
    print(head);
    return 0;
}