#include "Node.cpp"

void leftView(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        int size = q.size();

        int temp = -1;
        for (int i = 0; i < size; i++)
        {
            Node *front = q.front();
            q.pop();

            temp = front->data;

            if (front->left)
            {
                q.push(front->left);
            }
            if (front->right)
            {
                q.push(front->right);
            }
        }
        cout << temp << " ";
    }
}

int main()
{
    Node *root = NULL;
    root = buildTree(root);
    // 1 2  3 4 5 6 7 -1 -1 -1 -1 -1 -1 -1 -1
    cout << "Here is tree" << endl;
    LevelOrder(root);

    leftView(root);
    return 0;
}