#include "Node.cpp"

class info
{
public:
    int maxi;
    int mini;
    bool IsBst;
    int size;
};

info solve(Node *root, int &ans)
{
    if (root == NULL)
    {
        return {INT_MIN, INT_MAX, 1, 0};
    }

    info leftpart = solve(root->left, ans);
    info righttpart = solve(root->right, ans);

    info Curr;
    Curr.size = leftpart.size + righttpart.size + 1;
    Curr.maxi = max(righttpart.maxi, root->data);
    Curr.mini = min(leftpart.mini, root->data);

    bool check = (root->data > leftpart.maxi && root->data < righttpart.mini);

    if (leftpart.IsBst && righttpart.IsBst && check)
    {
        // current_exception
        Curr.IsBst = 1;
    }
    else
    {
        Curr.IsBst = 0;
    }

    if (Curr.IsBst)
    {
        ans = max(ans, Curr.size);
    }

    return Curr;
}

int MaxBst(Node *root)
{
    int ans = 0;
    info temp = solve(root, ans);
    return ans;
}
int main()
{
    Node *root = NULL;
    root = buildTree(root);
    // 1 2  3 4 5 6 7 -1 -1 -1 -1 -1 -1 -1 -1
    cout << "Here is tree" << endl;
    LevelOrder(root);

    cout << "\nMaximum BST is " << MaxBst(root) << endl;
    return 0;
}