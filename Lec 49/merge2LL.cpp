#include "Node.cpp"

// Node *solve(Node *head1, Node *head2)
// {
//     Node *next1 = head1->next, *curr1 = head1;
//     Node *next2 = head2->next, *curr2 = head2;
//     while ((next1 != NULL) && (next2 != NULL))
//     {
//         if ((curr2->data <= next1->data) && (curr2->data >= curr1->data))
//         {
//             curr1->next = curr2;
//             next2 = curr2->next;

//             curr2->next = next1;
//             curr1 = curr2;
//             curr2 = next2;
//         }
//         else
//         {
//             next1 = next1->next;
//             curr1 = curr1->next;
//             if (next1 == NULL)
//             {
//                 curr1->next = curr2;
//             }
//         }
//     }
//     return head1;
// }
// Node *merge(Node *head1, Node *head2)
// {
//     if (head1 == NULL)
//     {
//         return head2;
//     }
//     if (head2 == NULL)
//     {
//         return head1;
//     }
//     Node *ans = new Node(-1);
//     if (head1->data <= head2->data)
//     {
//         ans->next = solve(head1, head2);
//     }
//     else
//     {
//         ans->next = solve(head2, head1);
//     }
//     return ans->next;
// }
Node *merge(Node *head1, Node *head2)
{
    Node *temp1 = head1, *temp2 = head2;
    Node *ans = new Node(-1);
    Node *anshead = ans;
    while (temp1 != NULL && temp2 != NULL)
    {
        if (temp1->data < temp2->data)
        {
            Node *temp = new Node(temp1->data);
            anshead->next = temp;
            temp1 = temp1->next;
            anshead = anshead->next;
        }
        else
        {
            Node *temp = new Node(temp2->data);
            anshead->next = temp;
            temp2 = temp2->next;
            anshead = anshead->next;
        }
    }
    if (temp1 != NULL)
    {
        anshead->next = temp1;
    }
    else if (temp2 != NULL)
    {
        anshead->next = temp2;
    }
    return ans->next;
}

int main()
{
    Node *head1 = new Node(0);
    Node *node1 = new Node(10);
    Node *node2 = new Node(20);

    head1->next = node1;
    node1->next = node2;
    Node *head2 = new Node(30);
    Node *node4 = new Node(40);
    Node *node5 = new Node(50);
    head2->next = node4;
    node4->next = node5;
    print(head1);
    print(head2);
    Node *ans = merge(head1, head2);
    print(ans);
    return 0;
}