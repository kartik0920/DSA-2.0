#include "Node.cpp"

Node *LCA1(Node *root, int n1, int n2)
{

    if (root == NULL)
    {
        return NULL;
    }
    int d = root->data;
    if (d < n1 && d < n2)
    {
        return LCA1(root->right, n1, n2);
    }
    if (d > n1 && d > n2)
    {
        return LCA1(root->left, n1, n2);
    }
    return root;
}

Node *LCA2(Node *root, int n1, int n2)
{
    if (root == NULL)
        return NULL;

    Node *temp = root;
    while (temp != NULL)
    {
        int d = temp->data;
        if (d > n1 && d > n2)
        {
            temp = temp->left;
        }
        else if (d < n1 && d < n2)
        {
            temp = temp->right;
        }
        else
        {
            return temp;
        }
    }
    return temp;
}

int main()
{
    Node *root = NULL;
    root = buildTree(root);
    // 5 2 1 3 6 9 7 -1
    cout << "Here is tree" << endl;
    InOrder(root);
    cout << endl;
    cout << LCA1(root, 3, 2)->data << endl;
    cout << LCA2(root, 3, 2)->data << endl;
    cout << endl;
}