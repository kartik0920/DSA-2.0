#include "Node.cpp"

void LevelOrder(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        if (temp == NULL)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << ' ';
            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}
void InOrder(Node *root, vector<Node *> &arr)
{
    if (root == NULL)
    {
        return;
    }
    InOrder(root->left, arr);
    arr.push_back(root);
    InOrder(root->right, arr);
}
Node *BalanceBST(Node *root)
{
    vector<Node *> arr;
    InOrder(root, arr);
    int n = arr.size();
    for (int i = 0; i < n - 1; i++)
    {
        arr[i]->left = NULL;
        arr[i]->right = arr[i + 1];
    }
    arr[n - 1]->left = NULL;
    arr[n - 1]->right = NULL;
    return arr[0];
}
int main()
{
    Node *root = NULL;
    root = buildTree(root);
    // 5 2 1 3 6 9 7 -1
    cout << "Here is tree" << endl;
    InOrder(root);
    cout << endl;
    cout << endl;
    Node *r1 = BalanceBST(root);
    LevelOrder(r1);
    return 0;
}