#include "Node.cpp"

void traverseLeft(Node *root, vector<int> &ans)
{
    if (root == NULL || ((root->left == NULL) && (root->right == NULL)))
    {
        return;
    }
    ans.push_back(root->data);
    if (root->left)
        traverseLeft(root->left, ans);
    else
        traverseLeft(root->right, ans);
}

void taverseLeaf(Node *root, vector<int> &ans)
{
    if (root == NULL)
    {
        return;
    }
    if ((root->left == NULL) && (root->right == NULL))
    {
        ans.push_back(root->data);
    }
    taverseLeaf(root->left, ans);
    taverseLeaf(root->right, ans);
}

void traverseRight(Node *root, vector<int> &ans)
{
    if (root == NULL || (root->left == NULL && root->right == NULL))
    {
        return;
    }
    if (root->right)
        traverseRight(root->right, ans);
    else
        traverseRight(root->left, ans);
    ans.push_back(root->data);
}

vector<int> boundary(Node *root)
{
    vector<int> ans;
    if (root == NULL)
    {
        return ans;
    }
    ans.push_back(root->data);
    traverseLeft(root->left, ans);
    taverseLeaf(root->left, ans);
    taverseLeaf(root->right, ans);
    traverseRight(root->right, ans);
    return ans;
}

void print(vector<int> arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << ' ';
    }
    cout << endl;
}

int main()
{
    Node *root = NULL;
    root = buildTree(root);
    // 1 2 4 -1 -1 5 -1 -1 3 6 -1 -1 7 -1 -1
    cout << "Here is tree" << endl;
    LevelOrder(root);
    cout << "Travesesal is " << endl;
    vector<int> t = boundary(root);
    print(t);
    return 0;
}