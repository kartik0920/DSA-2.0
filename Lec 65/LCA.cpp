#include "Node.cpp"
Node *lca(Node *root, int n1, int n2)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->data == n1 || root->data == n2)
    {
        return root;
    }
    Node *leftside = lca(root->left, n1, n2);
    Node *rightside = lca(root->right, n1, n2);

    if (leftside != NULL && rightside != NULL)
    {
        return root;
    }
    else if (leftside != NULL && rightside == NULL)
    {
        return leftside;
    }
    else if (leftside == NULL && rightside != NULL)
    {
        return rightside;
    }
    else
    {
        return NULL;
    }
}
int main()
{
    Node *root = NULL;
    root = buildTree(root);
    // 1 2 4 -1 -1 5 -1 -1 3 6 -1 -1 7 -1 -1
    cout << "Here is tree" << endl;
    LevelOrder(root);
    cout << endl;

    Node *common = lca(root, 7, 6);
    cout << "LCA is " << common->data << endl;
    return 0;
}