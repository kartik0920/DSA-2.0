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
Node *buildTree(Node *root)
{
    int data;
    cout << "Enter data";
    cin >> data;
    root = new Node(data);
    if (data == -1)
    {
        return NULL;
    }
    cout << "Enter on left of " << data << endl;
    root->left = buildTree(root->left);
    cout << "Enter on right of " << data << endl;
    root->right = buildTree(root->right);
    return root;
}
void LevelOrder(Node *root)
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
