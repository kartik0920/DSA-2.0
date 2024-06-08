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
Node *InsertNode(Node *&root, int data)
{
    if (root == NULL)
    {
        root = new Node(data);
        return root;
    }
    if (data > root->data)
    {
        root->right = InsertNode(root->right, data);
    }
    else
    {
        root->left = InsertNode(root->left, data);
    }
    return root;
}
void Create(Node *&root)
{
    int data;
    cout << "Enter root";
    cin >> data;
    while (data != -1)
    {
        root = InsertNode(root, data);
        cin >> data;
    }
}

void inOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    inOrder(root->left);
    cout << root->data << ' ';
    inOrder(root->right);
}