#include "Node.cpp"
bool isIdentical(Node *r1, Node *r2)
{
    if (r1 == NULL && r2 == NULL)
    {
        return 1;
    }
    if (r1 == NULL && r2 != NULL || r1 != NULL && r2 == NULL)
    {
        return 0;
    }
    bool l = isIdentical(r1->left, r2->left);
    bool r = isIdentical(r1->right, r2->right);
    bool c = r1->data == r2->data;
    if (l & r & c)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int main()
{
    Node *r1 = NULL, *r2 = NULL;
    r1 = buildTree(r1);
    r2 = buildTree(r2);
    // 1 2 4 -1 -1 5 -1 -1 3 6 -1 -1 7 -1 -1
    cout << "Trees are :" << isIdentical(r1, r2) << endl;

    return 0;
}