#include "Node.cpp"

bool Solve(Node *root, int min, int max)
{
    if (root == NULL)
    {
        return 1;
    }

    int d = root->data;
    if (d >= min && d <= max)
    {
        bool leftside = Solve(root->left, min, d);
        bool rightside = Solve(root->right, d, max);
        return leftside && rightside;
    }
    else
    {
        return 0;
    }
}

bool ValidBst(Node *root)
{
    return Solve(root, INT32_MIN, INT32_MAX);
}

void Inorder(Node *root, vector<int> &ans)
{
    if (root == NULL)
    {
        return;
    }
    Inorder(root->left, ans);
    ans.push_back(root->data);
    Inorder(root->right, ans);
}

bool isBST(Node *root)
{
    if (root == NULL)
    {
        return 1;
    }
    vector<int> ans;
    Inorder(root, ans);
    if (ans.size() == 1)
    {
        return 1;
    }
    for (int i = 1; i < ans.size(); i++)
    {
        if (ans[i] <= ans[i - 1])
        {
            return 0;
        }
    }
    if (ans[0] < ans[ans.size() - 1])
    {
        return 1;
    }
    return 0;
}

int main()
{
    Node *root = NULL;
    root = buildTree(root);
    // 5 2 1 3 6 9 7 -1
    cout << "Here is tree" << endl;
    InOrder(root);
    cout << endl;
    if (ValidBst(root))
    {
        cout << "Correct" << endl;
    }
    else
    {
        cout << "Not correct" << endl;
    }
    return 0;
}