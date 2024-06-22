#include "Node.cpp"
void Inorder(Node *root, vector<int> &arr)
{
    if (root == NULL)
    {
        return;
    }
    Inorder(root->left, arr);
    arr.push_back(root->data);
    Inorder(root->right, arr);
}
int klarge1(Node *root, int k)
{
    vector<int> arr;
    Inorder(root, arr);
    return arr[k - 1];
}

int solve(Node *root, int &i, int k)
{
    if (root == NULL)
    {
        return -1;
    }
    int left = solve(root->left, i, k);
    if (left != -1)
    {
        return left;
    }
    i++;
    if (i == k)
    {
        return root->data;
    }
    return solve(root->right, i, k);
}

int klarge2(Node *root, int k)
{
    int i = 0;
    int ans = solve(root, i, k);
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
    int k = 2;
    cout << klarge1(root, k) << endl;
    cout << klarge2(root, k) << endl;
    return 0;
}