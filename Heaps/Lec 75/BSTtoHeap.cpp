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
void inOrder(Node *root, vector<int> &arr)
{
    if (root == NULL)
    {
        return;
    }
    inOrder(root->left, arr);
    arr.push_back(root->data);
    inOrder(root->right, arr);
}

void preOrderFix(vector<int> arr, Node *root, int &i)
{
    if (root == NULL)
    {
        return;
    }
    root->data = arr[i++];
    preOrderFix(arr, root->left, i);
    preOrderFix(arr, root->right, i);
}

Node *buildHeap(Node *root)
{
    vector<int> arr;
    inOrder(root, arr);

    int i = 0;
    preOrderFix(arr, root, i);
    return root;
}

int main()
{
    Node *root = NULL;
    root = buildTree(root);
    // 5 2 1 3 6 9 7 -1
    cout << "Here is tree" << endl;
    // InOrder(root);
    LevelOrder(root);
    // cout << endl;
    // root = buildHeap(root);

    return 0;
}