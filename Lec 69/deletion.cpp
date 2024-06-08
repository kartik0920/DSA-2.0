#include "Node.cpp"
int minValue(Node *root)
{
    int ans = -1;
    Node *temp = root;
    while (temp != NULL)
    {
        ans = temp->data;
        temp = temp->left;
    }
    return ans;
}
Node *deleteNode(Node *root, int x)
{
    if (root == NULL)
    {
        return root;
    }
    if (root->data > x)
    {
        root->left = deleteNode(root->left, x);
        return root;
    }
    else if (root->data < x)
    {
        root->right = deleteNode(root->right, x);
        return root;
    }
    else
    {
        // 0 child
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }

        // 1 child
        if (root->left != NULL && root->right == NULL)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }
        if (root->left == NULL && root->right != NULL)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }

        // 2 child
        if (root->left != NULL && root->right != NULL)
        {
            int minV = minValue(root->right);
            root->data = minV;
            root->right = deleteNode(root->right, minV);
            return root;
        }
    }
}
int main()
{
    Node *root = NULL;
    Create(root);
    // 2 3 1 4 8 -1
    inOrder(root);
    cout << endl;
    deleteNode(root, 3);
    inOrder(root);

    return 0;
}