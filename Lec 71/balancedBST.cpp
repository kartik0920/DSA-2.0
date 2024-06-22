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

void InOrder(Node *root, vector<int> &arr)
{
    if (root == NULL)
    {
        return;
    }
    InOrder(root->left, arr);
    arr.push_back(root->data);
    InOrder(root->right, arr);
}
Node *InsertNode(int s, int e, vector<int> &arr)
{
    if (s > e)
    {
        return NULL;
    }
    int mid = s + (e - s) / 2;
    Node *root = new Node(arr[mid]);
    root->left = InsertNode(s, mid - 1, arr);
    root->right = InsertNode(mid + 1, e, arr);

    return root;
}
Node *BalanceBST(Node *root)
{
    vector<int> arr;
    InOrder(root, arr);
    int n = arr.size() - 1;
    return InsertNode(0, n, arr);
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