#include "Node.cpp"

pair<int, int> solve(Node *root)
{
    if (root == NULL)
    {
        return {0, 0};
    }
    pair<int, int> left = solve(root->left);
    pair<int, int> right = solve(root->right);
    int height = max(left.first, right.first) + 1;
    int dia = max(left.second, max(right.second, left.first + right.first + 1));
    return {height, dia};
}

int diameter(Node *root)
{
    if (root == NULL)
    {
        return -1;
    }
    return solve(root).second;
}

int main()
{
    Node *root = NULL;
    root = buildTree(root);
    // 1 2  3 4 5 6 7 -1 -1 -1 -1 -1 -1 -1 -1
    cout << "Here is tree" << endl;
    LevelOrder(root);
    cout << diameter(root) << endl;
    return 0;
}