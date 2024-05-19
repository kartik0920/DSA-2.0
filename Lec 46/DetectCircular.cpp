#include "Node.cpp"
bool IsCircular1(Node *head)
{
    if (head == NULL)
    {
        return 0;
    }
    Node *temp = head->next;
    while (temp != NULL && temp != head)
    {
        temp = temp->next;
    }
    return temp == NULL ? 0 : 1;
}
bool IsCircular2(Node *head)
{
    unordered_map<Node *, bool> mapping;
    Node *temp = head;
    while (temp != NULL)
    {
        if (mapping[temp])
        {
            return 1;
        }
        mapping[temp] = 1;
        temp = temp->next;
    }
    return 0;
}
bool IsCircular3(Node *head)
{
    if (head == NULL)
    {
        return 0;
    }
    if (head->next == head)
    {
        return 1;
    }
    if (head->next == NULL)
    {
        return 0;
    }

    Node *slow = head, *fast = head;
    while (fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            fast = fast->next;
        }
        slow = slow->next;
        if (fast == slow)
        {
            return 1;
        }
    }
    return 0;
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
    // node5->next = head;
    // if (IsCircular1(head))
    // {
    //     cout << "Circular LL" << endl;
    // }
    // else
    // {
    //     cout << "Not circular LL" << endl;
    // }

    // if (IsCircular2(head))
    // {
    //     cout << "Circular LL" << endl;
    // }
    // else
    // {
    //     cout << "Not circular LL" << endl;
    // }

    if (IsCircular3(head))
    {
        cout << "Circular LL" << endl;
    }
    else
    {
        cout << "Not circular LL" << endl;
    }

    return 0;
}