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

void solve(Node *root, int &cnt)
{
    if (root == NULL)
    {
        return;
    }
    if (root->left == NULL && root->right == NULL)
    {
        cnt++;
    }
    solve(root->left, cnt);
    solve(root->right, cnt);
}

int NoOfLeaves(Node *root)
{
    int cnt = 0;
    solve(root, cnt);
    return cnt;
}
int main()
{
    Node *root = NULL;
    root = buildTree(root);
    // 1 2 4 -1 -1 5 -1 -1 3 6 -1 -1 7 -1 -1
    cout << endl;
    cout << NoOfLeaves(root) << endl;
    return 0;
}