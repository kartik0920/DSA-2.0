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
    if (index < 0 || inStart > inEnd)
    {
        return NULL;
    }
    int element = pre[index--];
    Node *root = new Node(element);
    int position = LS(in, n, element);
    // index++;
    // left and right
    root->right = solve(in, pre, n, index, position + 1, inEnd);
    root->left = solve(in, pre, n, index, inStart, position - 1);

    return root;
}
// Function to return a tree created from postorder and inoreder traversals.
Node *buildTree(int in[], int post[], int n)
{
    int index = n - 1;
    int inStart = 0, inEnd = n - 1;
    Node *root = solve(in, post, n, index, 0, n - 1);
    return root;
}
int main()
{
    int n = 8;

    int in[] = {4, 8, 2, 5, 1, 6, 3, 7};
    int post[] = {8, 4, 5, 2, 6, 7, 3, 1};
    Node *root = buildTree(in, post   , n);
    LevelOrder(root);
    return 0;
}