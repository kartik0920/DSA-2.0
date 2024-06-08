#include "Node.cpp"
Node *BS(Node *root, int x)
{
    Node *temp = root;
    while (temp != NULL)
    {
        if (temp->data == x)
        {
            return temp;
        }
        else if (temp->data > x)
        {
            temp = temp->left;
        }
        else
        {
            temp = temp->right;
        }
    }
    return NULL;
}
Node *MinVal(Node *root)
{
    Node *temp = root;
    while (temp->left != NULL)
    {
        temp = temp->left;
    }
    return temp;
}
Node *inOrderSuccessor(Node *root, Node *x)
{
    int y = x->data;
    Node *present = BS(root, y);
    return MinVal(present->right);
}
int main()
{
    Node *root = NULL;
    Create(root);
    // 2 3 1 4 8 -1
    inOrder(root);

    cout << "Sucesor is " << inOrderSuccessor(root, root)->data << endl;
    return 0;
}