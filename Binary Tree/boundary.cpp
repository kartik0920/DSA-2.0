#include "Node.cpp"

void solveLeft(Node *root, vector<int> &arr)
{
    if (root == NULL)
    {
        return;
    }
    Node *temp = root;
    while (temp->left != NULL && temp->right != NULL)
    {
        arr.push_back(temp->data);
        if (temp->left)
        {
            temp = temp->left;
        }
        else
        {
            temp = temp->right;
        }
    }
}
void solveRight(Node *root, vector<int> &arr)
{
    if (root == NULL)
    {
        return;
    }
    Node *temp = root;
    while (temp->left != NULL && temp->right != NULL)
    {
        arr.push_back(temp->data);
        if (temp->right)
        {
            temp = temp->right;
        }
        else
        {
            temp = temp->left;
        }
    }
}

void solveLeaf(Node *root, vector<int> &arr)
{
    if (root == NULL)
    {
        return;
    }
    if (root->left == NULL && root->right == NULL)
    {
        arr.push_back(root->data);
    }
    solveLeaf(root->left, arr);
    solveLeaf(root->right, arr);
}

vector<int> boundary(Node *root)
{
    vector<int> ans;
    ans.push_back(root->data);
    solveLeft(root->left, ans);
    solveLeaf(root, ans);
    solveRight(root->right, ans);
    return ans;
}

int main()
{
    Node *root = NULL;
    root = buildTree(root);
    // 1 2  3 4 5 6 7 -1 -1 -1 -1 -1 -1 -1 -1
    cout << "Here is tree" << endl;
    LevelOrder(root);

    vector<int> ans = boundary(root);
    for (auto i : ans)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}