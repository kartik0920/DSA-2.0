#include "Node.cpp"
bool search(TreeNode *root, int x)
{
    TreeNode *temp = root;
    while (temp != NULL)
    {
        if (temp->val == x)
        {
            return 1;
        }
        else if (temp->val < x)
        {
            temp = temp->right;
        }
        else
        {
            temp = temp->left;
        }
    }
    return 0;
}
int main()
{
    Node *root = NULL;
    Create(root);
    // 2 3 1 4 8 -1
    inOrder(root);
    cout << endl;
    cout << search(root, 53) << endl;

    return 0;
}