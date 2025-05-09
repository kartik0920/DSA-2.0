#include "Node.cpp"

void solve(Node *root, vector<int> &arr, vector<int> &temp, int x)
{
    if (root == NULL)
    {
        return;
    }
    if (root->data == x)
    {
        temp.push_back(x);
        arr = temp;
        return;
    }
    temp.push_back(root->data);
    solve(root->left, arr, temp, x);
    solve(root->right, arr, temp, x);
    temp.pop_back();
}

vector<int> getPath(Node *root, int x)
{
    if (root == NULL)
    {
        return {};
    }
    vector<int> ans, temp;
    solve(root, ans, temp, x);
    return ans;
}

int main()
{
    Node *root = NULL;
    root = buildTree(root);
    // 1 2  3 4 5 6 7 -1 -1 -1 -1 -1 -1 -1 -1
    cout << "Here is tree" << endl;
    LevelOrder(root);

    vector<int> path = getPath(root, 7);
    for (auto i : path)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}