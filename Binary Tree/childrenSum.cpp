#include "Node.cpp"

Node *getChildrensum(Node *root)
{
    if (root->left == NULL && root->right == NULL)
    {
        return root;
    }
    int left = getChildrensum(root->left)->data;
    int right = getChildrensum(root->right)->data;
    root->data = left + right;
    return root;
}

int main()
{
    Node *root = NULL;
    root = buildTree(root);
    // 1 2  3 4 5 6 7 -1 -1 -1 -1 -1 -1 -1 -1
    cout << "Here is tree" << endl;
    LevelOrder(root);

    Node *ans = getChildrensum(root);
    LevelOrder(ans);
    return 0;
}