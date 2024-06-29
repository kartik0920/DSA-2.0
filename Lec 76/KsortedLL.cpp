#include "Node.cpp"
class compare
{
public:
    bool operator()(Node *a, Node *b)
    {
        return a->data > b->data;
    }
};
Node *mergeKLists(Node *arr[], int K)
{
    priority_queue<Node *, vector<Node *>, compare> pq;
    for (int i = 0; i < K; i++)
    {
        if (arr[i] != NULL)
            pq.push(arr[i]);
    }

    Node *head = new Node(-1);
    Node *tail = head;

    while (!pq.empty())
    {
        Node *top = pq.top();
        pq.pop();
        if (top->next != NULL)
        {
            pq.push(top->next);
        }
        tail->next = top;
        tail = top;
    }
    return head->next;
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
    print(head);
    return 0;
}