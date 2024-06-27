// Here we have check wheter the binary tree is heap
#include "Node.cpp"

int count(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return count(root->left) + count(root->right) + 1;
}

bool IsCBT(Node *root, int cnt, int index)
{
    if (root == NULL)
    {
        return 1;
    }
    if (index >= cnt)
    {
        return 0;
    }
    else
    {
        bool left = IsCBT(root->left, cnt, index * 2 + 1);
        bool right = IsCBT(root->right, cnt, index * 2 + 2);
        return left && right;
    }
}

bool IsMax(Node *root)
{
    if (root->left == NULL && root->right == NULL)
    {
        return 1;
    }
    else if (root->right == NULL)
    {
        return root->data > root->left->data;
    }
    else
    {
        bool left = IsMax(root->left);
        bool right = IsMax(root->right);
        bool check = root->data > root->left->data && root->data > root->right->data;
        if (left && right && check)
        {
            return 1;
        }
        return 0;
    }
}
bool IsHeap(Node *root)
{
    if (root == NULL)
    {
        return 1;
    }
    int index = 0;
    int cnt = count(root);
    return IsCBT(root, cnt, index) & IsMax(root);
}
int main()
{
    Node *root = NULL;
    root = buildTree(root);
    // 1 2  3 4 5 6 7 -1 -1 -1 -1 -1 -1 -1 -1
    cout << "Here is tree" << endl;
    LevelOrder(root);

    cout << endl;
    cout << "Here is solution:" << IsHeap(root) << endl;
    return 0;
}