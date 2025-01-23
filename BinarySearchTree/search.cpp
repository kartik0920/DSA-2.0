#include "Node.cpp"

bool search(Node *root, int key)
{
    Node *temp = root;

    while (temp != NULL)
    {
        if (temp->data == key)
        {
            return 1;
        }
        else if (temp->data < key)
        {
            temp = temp->right;
        }
        else
        {
            temp = temp->left;
        }
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
    int key = 5;
    cout << search(root, key) << endl;
    return 0;
}