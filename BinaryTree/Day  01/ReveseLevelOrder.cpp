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
    stack<vector<int>> st;
    while (!q.empty())
    {
        int size = q.size();
        vector<int> temp;
        for (int i = 0; i < size; i++)
        {
            Node *front = q.front();
            q.pop();
            temp.push_back(front->data);
            if (front->left)
            {
                q.push(front->left);
            }
            if (front->right)
            {
                q.push(front->right);
            }
        }
        st.push(temp);
    }

    while (!st.empty())
    {
        vector<int> i = st.top();
        st.pop();
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
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