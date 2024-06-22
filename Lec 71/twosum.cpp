#include "Node.cpp"
void InOrderArr(Node *root, vector<int> &arr)
{
    if (root == NULL)
    {
        return;
    }
    InOrderArr(root->left, arr);
    arr.push_back(root->data);
    InOrderArr(root->right, arr);
}
bool twosum(Node *root, int target)
{
    vector<int> arr;
    InOrderArr(root, arr);
    int i = 0;
    int j = arr.size() - 1;
    while (j > i)
    {
        int sum = arr[i] + arr[j];
        if (sum == target)
        {
            return 1;
        }
        else if (sum > target)
        {
            j--;
        }
        else
        {
            i++;
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
    cout << twosum(root, 8) << endl;
    return 0;
}