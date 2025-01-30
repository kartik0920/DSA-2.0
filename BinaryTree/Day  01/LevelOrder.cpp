#include "Node.cpp"

void thisLevelOrder(Node *root)
{
    if (
        root == NULL)
    {
        cout << "Empty TREE";
        return;
    }
    Node *temp = root;
    queue<Node *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        Node *top = q.front();
        q.pop();
        if (top == NULL)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
            continue;
        }
        cout << top->data << " ";
        if (top->left)
        {
            q.push(top->left);
        }
        if (top->right)
        {
            q.push(top->right);
        }
    }
}

int main()
{
    Node *root = NULL;
    root = buildTree(root);
    // 1 2  3 4 5 6 7 -1 -1 -1 -1 -1 -1 -1 -1
    cout << "Here is tree" << endl;
    thisLevelOrder(root);
    return 0;
}