#include "Node.cpp"

Node *solve(int mini, int maxi, int *pre, int &i, int size)
{
    if (i < 0)
    {
        return NULL;
    }
    if (pre[i] > maxi || pre[i] < mini)
    {
        return NULL;
    }
    Node *root = new Node(pre[i--]);

    root->right = solve(root->data, maxi, pre, i, size);
    root->left = solve(mini, root->data, pre, i, size);

    return root;
}

Node *constructTree(int pre[], int size)
{
    int i = size - 1;

    int mini = INT32_MIN;
    int maxi = INT32_MAX;
    return solve(mini, maxi, pre, i, size);
}
int main()
{
    Node *root = NULL;
    int pre[] = {1, 7, 5, 5, 0, 40, 10};
    int size = sizeof(pre) / sizeof(pre[0]);
    root = constructTree(pre, size);
    // 5 2 1 3 6 9 7 -1
    cout << "Here is tree" << endl;
    InOrder(root);
    cout << endl;

    return 0;
}