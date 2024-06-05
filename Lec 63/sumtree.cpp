#include "Node.cpp"
pair<bool, int> solve(Node *root)
{
    if (root == NULL)
    {
        return {1, 0};
    }
    if (root->left == NULL && root->right == NULL)
    {
        return {1, root->data};
    }
    pair<bool, int> lp = solve(root->left);
    pair<bool, int> rp = solve(root->right);

    bool lcheck = lp.first;
    bool rcheck = rp.first;
    bool sum = root->data == lp.second + rp.second;
    if (lcheck && rcheck && sum)
    {
        return {1, 2 * root->data};
    }
    else
    {
        return {0, sum};
    }
}
bool isSumTree(Node *root)
{
    // Your code here
    pair<bool, int> ans = solve(root);
    return ans.first;
}
int main()
{
    Node *root = NULL;
    root = buildTree(root);
    // 1 2 4 -1 -1 5 -1 -1 3 6 -1 -1 7 -1 -1
    cout << endl;
    cout << "Is sum tree:" << isSumTree(root) << endl;
}