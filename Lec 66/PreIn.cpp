#include "Node.cpp"
int LS(int *arr, int n, int x)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == x)
        {
            return i;
        }
    }
    return -1;
}
Node *solve(int *in, int *pre, int n, int &index, int inStart, int inEnd)
{
    if (index >= n || inStart > inEnd)
    {
        return NULL;
    }
    int element = pre[index];
    int position = LS(in, n, element);
    Node *root = new Node(element);
    index++;
    // left and right
    root->left = solve(in, pre, n, index, inStart, position - 1);
    root->right = solve(in, pre, n, index, position + 1, inEnd);

    return root;
}
Node *buildTree(int in[], int pre[], int n)
{
    int index = 0;
    int inStart = 0, inEnd = n - 1;
    Node *root = solve(in, pre, n, index, inStart, inEnd);
    return root;
}
int main()
{
    int n = 6;

    int in[] = {3, 1, 4, 0, 5, 2};
    int pre[] = {0, 1, 3, 4, 2, 5};
    Node *root = buildTree(in, pre, n);
    LevelOrder(root);
    return 0;
}