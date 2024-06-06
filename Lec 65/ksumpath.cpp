#include "Node.cpp"
void solve(Node *root, int k, vector<int> &path)
{
    if (root == NULL)
    {
        return;
    }
    if (root->data == k)
    {
        path.push_back(root->data);
    }
    path.push_back(root->data);
    solve(root->left, k, path);
    solve(root->right, k, path);
    path.pop_back();
}
vector<int> sumK(Node *root, int k)
{
    vector<int> path;

    solve(root, k, path);
    return path;
}
int main()
{
    Node *root = NULL;
    root = buildTree(root);
    // 1 2 4 -1 -1 5 -1 -1 3 6 -1 -1 7 -1 -1
    cout << "Here is tree" << endl;
    LevelOrder(root);
    cout << endl;
    vector<int> t = sumK(root, 4);
    for (int i = 0; i < t.size(); i++)
    {
        cout << t[i] << ' ';
    }
    cout << endl;
    return 0;
}