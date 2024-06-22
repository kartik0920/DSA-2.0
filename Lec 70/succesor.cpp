#include "Node.cpp"
int succ(Node *root, int key)
{
    int ans = -1;
    // Node* keyNode=NULL;
    while (root->data != key)
    {
        int d = root->data;
        if (d > key)
        {
            ans = d;
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }
    root = root->right;
    while (root != NULL)
    {
        ans = root->data;
        root = root->left;
    }
    return ans;
}
int main()
{
    Node *root = NULL;
    root = buildTree(root);
    // 5 2 1 3 6 9 7 -1
    cout << "Here is tree" << endl;
    InOrder(root);
    cout << endl;
    int key = 6;
    cout << succ(root, key);
    cout << endl;
}