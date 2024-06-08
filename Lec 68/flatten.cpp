#include "Node.cpp"
void print(Node *root)
{
    Node *curr = root;
    while (curr != NULL)
    {
        cout << curr->data << ' ';
        curr = curr->right;
    }
    cout << endl;
}
void flatten(Node *root)
{
    Node *curr = root;
    while (curr != NULL)
    {
        if (curr->left)
        {
            Node *pred = curr->left;
            while (pred->right)
            {
                pred = pred->right;
            }
            pred->right = curr->right;
            curr->right = curr->left;
            curr->left = NULL;
            ;
        }
        curr = curr->right;
    }
}
int main()
{
    Node *root = NULL;
    root = CreateLevel(root);
    // 1 2 3 4 5 6 7 -1 -1 -1 -1 -1 -1 -1 -1\

    // 1,2,5,3,4,-1,6
    cout << "Here is tree" << endl;
    // LevelOrder(root);
    print(root);
    return 0;
}