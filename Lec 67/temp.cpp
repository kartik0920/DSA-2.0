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
int main()
{
    Node *root = NULL;
    root = CreateLevel(root);
    // 1 2 3 4 5 6 7 -1 -1 -1 -1 -1 -1 -1 -1
    cout << "Here is tree" << endl;
    LevelOrder(root);
    return 0;
}