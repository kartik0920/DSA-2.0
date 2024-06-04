#include <bits/stdc++.h>
#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *left, *right;
    Node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

void Levelorder(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        if (temp == NULL)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << ' ';
            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}
Node *CreateValue(Node *root)
{
    int d;
    cout << "Enter data:";
    cin >> d;
    root = new Node(d);
    if (d == -1)
    {
        return NULL;
    }
    // cout << "left" << root->data << endl;
    root->left = CreateValue(root->left);
    // cout << "right" << root->data << endl;
    root->right = CreateValue(root->right);
    return root;
}
Node *CreateLevel(Node *root)
{
    queue<Node *> q;
    int d;
    cout << "Enter root";
    cin >> d;
    root = new Node(d);
    q.push(root);
    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        int l, r;
        cout << "Enter l of " << temp->data << endl;
        cin >> l;
        if (l != -1)
        {
            temp->left = new Node(l);
            q.push(temp->left);
        }
        cout << "Enter r of " << temp->data << endl;
        cin >> r;
        if (r != -1)
        {
            temp->right = new Node(r);
            q.push(temp->right);
        }
    }
    return root;
}
int main()
{
    // 1 2 4 -1 -1 5 -1 -1 3 6 -1 -1 7 -1 -1
    Node *root = NULL;
    root = CreateLevel(root);
    cout << endl;
    Levelorder(root);
    return 0;
}