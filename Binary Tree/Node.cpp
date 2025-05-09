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
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        Node *frontNode = q.front();
        q.pop();
        cout << "Enter on left of " << frontNode->data;
        cin >> data;
        if (data != -1)
        {
            Node *temp = new Node(data);
            frontNode->left = temp;
            q.push(temp);
        }
        cout << "Enter on right of " << frontNode->data;
        cin >> data;
        if (data != -1)
        {
            Node *temp = new Node(data);
            frontNode->right = temp;
            q.push(temp);
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
