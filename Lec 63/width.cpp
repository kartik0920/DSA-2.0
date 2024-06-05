#include "Node.cpp"
int height(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int l = height(root->left);
    int r = height(root->right);
    return (max(l, r) + 1);
}
int diameter1(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int op1 = diameter1(root->left);
    int op2 = diameter1(root->right);
    int op3 = height(root->left) + height(root->right) + 1;
    int ans = max(op1, max(op2, op3));
    return ans;
}

pair<int, int> solve(Node *root)
{
    if (root == NULL)
    {
        return {0, 0};
    }
    pair<int, int> l = solve(root->left);
    pair<int, int> r = solve(root->right);
    int op1 = l.first;
    int op2 = r.first;
    int op3 = l.second + r.second + 1;
    int ans1 = max(op1, max(op2, op3));
    int ans2 = max(l.second, r.second) + 1;
    return {ans1, ans2};
}
int diameter2(Node *root)
{
    pair<int, int> ans = solve(root);
    return ans.first;
}

int main()
{
    Node *root = NULL;
    root = buildTree(root);
    // 1 2 4 -1 -1 5 -1 -1 3 6 -1 -1 7 -1 -1
    cout << "Here is tree" << endl;
    LevelOrder(root);
    cout << "Diameter is :" << diameter1(root) << endl;
    cout << "Diameter is :" << diameter2(root) << endl;
    return 0;
}