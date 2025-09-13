#include "Node.cpp"

void inOrder(Node *root, vector<int> &arr)
{
    if (root == NULL)
    {
        return;
    }
    inOrder(root->left, arr);
    arr.push_back(root->data);
    inOrder(root->right, arr);
}

pair<int, int> solve(Node *root, int x)
{
    vector<int> arr;
    inOrder(root, arr);
    int pre = -1, succ = -1;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == x)
        {
            pre = arr[i - 1];
            succ = arr[i + 1];
            break;
        }
    }
    return {pre, succ};
}

int main()
{
    Node *root = NULL;
    root = buildTree(root);
    // 5 2 1 3 6 9 7 -1
    cout << "Here is tree" << endl;
    InOrder(root);
    cout << endl;

    cout << solve(root, 3).first << " & " << solve(root, 3).second << endl;
    return 0;
}