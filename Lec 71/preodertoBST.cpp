#include "Node.cpp"

Node *solve(int mini, int maxi, vector<int> &pre, int &i, int size)
{
    if (i >= size)
    {
        return NULL;
    }
    if (pre[i] > maxi || pre[i] < mini)
    {
        return NULL;
    }
    Node *root = new Node(pre[i++]);

    root->left = solve(mini, root->data, pre, i, size);
    root->right = solve(root->data, maxi, pre, i, size);

    return root;
}

Node *PreToTree(vector<int> pre)
{
    int i = 0;
    int size = pre.size();
    int mini = INT32_MIN;
    int maxi = INT32_MAX;
    return solve(mini, maxi, pre, i, size);
}

int main()
{
    Node *root = NULL;
    vector<int> pre = {5, 1, 2, 3, 6, 7, 9};
    root = PreToTree(pre);
    // 5 2 1 3 6 9 7 -1
    cout << "Here is tree" << endl;
    InOrder(root);
    cout << endl;

    return 0;
}