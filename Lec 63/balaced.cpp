#include "Node.cpp"
int height(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int l = height(root->left);
    int r = height(root->right);
    int ans = max(l, r) + 1;
    return ans;
}
bool IsBalanced1(Node *root)
{
    if (root == NULL)
    {
        return 1;
    }
    bool l = IsBalanced1(root->left);
    bool r = IsBalanced1(root->right);
    bool var = abs(height(root->left) - height(root->right)) <= 1;
    if (l && r && var)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

pair<bool, int> solve(Node *root)
{
    if (root == NULL)
    {
        return {1, 0};
    }
    pair<bool, int> l = solve(root->left);
    pair<bool, int> r = solve(root->right);
    bool lcech = l.first;
    bool rcech = r.first;
    bool c = abs(l.second - r.second) <= 1;

    int h = max(l.second, r.second) + 1;
    return {c, h};
}
bool IsBalanced2(Node *root)
{
    pair<bool, int> ans = solve(root);
    return ans.first;
}
int main()
{
    Node *root = NULL;
    root = buildTree(root);
    // 1 2 4 -1 -1 5 -1 -1 3 6 -1 -1 7 -1 -1
    cout << "Here is tree" << endl;
    LevelOrder(root);
    cout << "Tree is :" << IsBalanced1(root) << endl;
    cout << "Tree is :" << IsBalanced2(root) << endl;
    return 0;
}