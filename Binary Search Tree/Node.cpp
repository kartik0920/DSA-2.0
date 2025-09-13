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
Node *InsertNode(Node *root, int key)
{
    if (root == NULL)
    {
        root = new Node(key);
        return root;
    }
    if (root->data > key)
    {
        root->left = InsertNode(root->left, key);
    }
    else
    {
        root->right = InsertNode(root->right, key);
    }
    return root;
}
Node *buildTree(Node *root)
{
    int data;
    cout << "enter root" << endl;
    cin >> data;
    root = new Node(data);
    do
    {
        cout << "Enter number: ";
        cin >> data;
        if (data == -1)
        {
            break;
        }
        root = InsertNode(root, data);
    } while (1);
    return root;
}
void InOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    InOrder(root->left);
    cout << root->data << ' ';
    InOrder(root->right);
}
