#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};
void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << ' ';
        temp = temp->next;
    }
    cout << endl;
}

class Tnode
{
public:
    int data;
    Node *next;
    Tnode(int d, Node *next)
    {
        this->data = d;
        this->next = next;
    }
};

class compare
{
public:
    bool operator()(Tnode *a, Tnode *b)
    {
        return a->data > b->data;
    }
};

Node *solve(vector<Node *> arr)
{
    int k = arr.size();
    priority_queue<Tnode *, vector<Tnode *>, compare> pq;
    for (int i = 0; i < k; i++)
    {
        Tnode *temp = new Tnode(arr[i]->data, arr[i]->next);
        pq.push(temp);
    }
    Node *ans = new Node(-1);
    Node *tail = ans;

    while (!pq.empty())
    {
        Tnode *temp = pq.top();
        pq.pop();
        tail->next = new Node(temp->data);
        tail = tail->next;
        if (temp->next != NULL)
        {
            Tnode *topush = new Tnode(temp->next->data, temp->next->next);
            pq.push(topush);
        }
    }
    return ans->next;
}

int main()
{
    Node *head1 = new Node(0);
    Node *node1 = new Node(10);
    Node *node2 = new Node(20);
    Node *node3 = new Node(30);
    Node *node4 = new Node(40);
    Node *node5 = new Node(50);
    head1->next = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    Node *head2 = new Node(-10);
    head2->next = node1;
    vector<Node *> arr = {head1, head2};

    Node *ans = solve(arr);
    print(ans);
    return 0;
}