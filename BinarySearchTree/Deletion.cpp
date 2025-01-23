#include "Node.cpp"

int getMax(Node *root)
{
    Node *temp = root;
    int data = root->data;
    while (temp != NULL)
    {
        data = temp->data;
        temp = temp->right;
    }
    return data;
}

Node *deleteNode(Node *root, int d)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->data == d)
    {
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }
        else if (root->left != NULL && root->right == NULL)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }
        else if (root->left == NULL && root->right != NULL)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }
        else
        {
            int x = getMax(root->left);
            root->data = x;
            root->left = deleteNode(root->left, x);
            return root;
        }
    }
    else if (root->data < d)
    {
        root->right = deleteNode(root->right, d);
        return root;
    }
    else
    {
        root->left = deleteNode(root->left, d);
        return root;
    }
}

int main()
{
    Node *root = NULL;
    root = buildTree(root);
    // 5 2 1 3 6 9 7 -1
    cout << "Here is tree" << endl;
    InOrder(root);
    cout << endl;
    deleteNode(root, 5);
    InOrder(root);
    return 0;
}