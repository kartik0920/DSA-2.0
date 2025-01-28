#include "Node.cpp"

int countNodes(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    return (1 + countNodes(root->left) + countNodes(root->right));
}

bool isCbt(Node *root, int cnt, int i)
{
    if (root == NULL)
    {
        return 1;
    }

    if (i >= cnt)
    {
        return 0;
    }
    else
    {
        bool left = isCbt(root->left, cnt, 2 * i + 1);
        bool right = isCbt(root->right, cnt, 2 * i + 2);
        return (left && right);
    }
}

bool isMaxHeap(Node *root)
{
    if (root->left == NULL && root->right == NULL)
    {
        return 1;
    }

    if (root->right == NULL)
    {
        return (root->data > root->left->data);
    }
    else
    {
        bool left = isMaxHeap(root->left);
        bool right = isMaxHeap(root->right);
        return (left && right &&
                root->data > root->left->data &&
                root->data > root->right->data);
    }
}

bool isHeap(Node *root)
{
    int n = countNodes(root);

    return isCbt(root, n, 0) && isMaxHeap(root);
}

int main()
{
    Node *root = NULL;
    root = buildTree(root);
    // 1 2  3 4 5 6 7 -1 -1 -1 -1 -1 -1 -1 -1
    cout << "Here is tree" << endl;
    LevelOrder(root);

    cout << isHeap(root) << endl;
    return 0;
}