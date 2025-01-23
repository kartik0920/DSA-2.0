#include "Node.cpp"

pair<int, int> minMax(Node *root)
{
    if (root == NULL)
    {
        return make_pair(-1, -1);
    }
    Node *temp = root;
    int min = root->data, max = root->data;
    while (temp != NULL)
    {
        min = temp->data;
        temp = temp->left;
    }
    temp = root;
    while (temp != NULL)
    {
        max = temp->data;
        temp = temp->right;
    }
    return make_pair(min, max);
}

int main()
{
    Node *root = NULL;
    root = buildTree(root);
    // 5 2 1 3 6 9 7 -1
    cout << "Here is tree" << endl;
    InOrder(root);
    cout << endl;

    cout << "min and max is " << minMax(root).first << "&" << minMax(root).second << endl;
    return 0;
}