#include "Node.cpp"
Node *solve(Node *root, int &k, int node)
{
    if (root == NULL || root->data == node)
    {
        return root;
    }

    Node *leftside = solve(root->left, k, node);
    Node *rightside = solve(root->right, k, node);
    if (leftside != NULL && rightside == NULL)
    {
        k--;
        if (k <= 0)
        {
            k = INT_MAX;
            return root;
        }
        return leftside;
    }
    if (leftside == NULL && rightside != NULL)
    {
        k--;
        if (k <= 0)
        {
            k = INT_MAX;
            return root;
        }
        return rightside;
    }
    // if (leftside == NULL && rightside == NULL)

    return NULL;
}
int kthAncestor(Node *root, int k, int node)
{
    Node *kth = solve(root, k, node);
    if (kth == NULL || kth->data == node)
    {
        return -1;
    }
    else
    {
        return kth->data;
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
    cout << "Kth integer  is " << kthAncestor(root, 1, 4) << endl;
    return 0;
}