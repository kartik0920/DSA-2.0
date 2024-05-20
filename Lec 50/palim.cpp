#include "Node.cpp"

bool ispa1i1(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return 1;
    }
    vector<int> arr;
    Node *temp = head;
    while (temp != NULL)
    {
        arr.push_back(temp->data);
        temp = temp->next;
    }
    int s = 0, e = arr.size() - 1;
    while (e >= s)
    {
        if (arr[s] != arr[e])
        {
            return 0;
        }
        s++;
        e--;
    }
    return 1;
}

Node *getMid(Node *head)
{
    Node *slow = head, *fast = head->next;
    if (fast->next == NULL || fast == NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

Node *reverse(Node *head)
{
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

bool ispali2(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return 1;
    }
    Node *mid = getMid(head);
    mid->next = reverse(mid->next);
    Node *temp1 = head, *temp2 = mid->next;
    while (temp2 != NULL)
    {
        if (temp1->data != temp2->data)
        {
            return 0;
        }
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    mid->next = reverse(mid->next);
    return 1;
}
int main()
{
    Node *head = new Node(0);
    Node *node1 = new Node(1);
    Node *node2 = new Node(2);
    Node *node3 = new Node(2);
    Node *node4 = new Node(1);
    Node *node5 = new Node(0);
    head->next = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    cout << ispali2(head) << endl;
    // cout << ispa1i2(head) << endl;
    return 0;
}