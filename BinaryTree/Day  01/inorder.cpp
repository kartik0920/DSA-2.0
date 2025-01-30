#include "Node.cpp"

void inOrderR(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    inOrderR(root->left);
    cout << root->data << " ";
    inOrderR(root->right);
}

void inOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    stack<Node *> st;
    // st.push(root);
    Node *temp = root;
    while (temp != NULL || !st.empty())
    {
        while (temp != NULL)
        {
            st.push(temp);
            temp = temp->left;
        }

        temp = st.top();
        cout << st.top()->data << " ";
        st.pop();
        temp = temp->right;
    }
}

int main()
{
    Node *root = NULL;
    root = buildTree(root);
    // 1 2  3 4 5 6 7 -1 -1 -1 -1 -1 -1 -1 -1
    cout << "Here is tree" << endl;
    LevelOrder(root);
    inOrderR(root);
    cout << endl;
    inOrder(root);
    return 0;
}