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
int MaxValue(Node *root)
{
    int ans = -1;
    Node *temp = root;
    while (temp != NULL)
    {
        ans = temp->data;
        temp = temp->right;
    }
    return ans;
}
int main()
{
    Node *root = NULL;
    Create(root);
    // 2 3 1 4 8 -1
    inOrder(root);
    cout << endl;
    cout << minValue(root) << endl;
    cout << MaxValue(root) << endl;

    return 0;
}