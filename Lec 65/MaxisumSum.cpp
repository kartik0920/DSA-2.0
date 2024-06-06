#include "Node.cpp"
pair<int, int> solve(Node *root)
{
    if (root == NULL)
    {
        return {0, 0};
    }
    pair<int, int> leftside = solve(root->left);
    pair<int, int> rightside = solve(root->right);

    pair<int, int> result;
    result.first = root->data + leftside.second + rightside.second;
    result.second = max(leftside.first, leftside.second) + max(rightside.first, rightside.second);
    return result;
}
int getMaxSum(Node *root)
{
    pair<int, int> ans = solve(root);
    return max(ans.first, ans.second);
}
int main()
{
    Node *root = NULL;
    root = buildTree(root);
    // 1 2 4 -1 -1 5 -1 -1 3 6 -1 -1 7 -1 -1
    cout << "Here is tree" << endl;
    LevelOrder(root);
    cout << endl;
    cout << "Sum is " << getMaxSum(root) << endl;
    return 0;
}