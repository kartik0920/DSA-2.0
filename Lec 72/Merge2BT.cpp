#include "Node.cpp"

void InOrder(Node *root, vector<int> &arr)
{
    if (root == NULL)
    {
        return;
    }
    InOrder(root->left, arr);
    arr.push_back(root->data);
    InOrder(root->right, arr);
}

vector<int> MergeArr(vector<int> &arr1, vector<int> &arr2)
{
    int n = arr1.size();
    int m = arr2.size();
    vector<int> ans(m + n);
    int i = 0, j = 0, k = 0;
    while (i < n & j < m)
    {
        if (arr1[i] < arr2[j])
        {
            ans[k++] = arr1[i++];
        }
        else
        {
            ans[k++] = arr2[j++];
        }
    }
    while (i < n)
    {
        ans[k++] = arr1[i++];
    }
    while (j < m)
    {
        ans[k++] = arr2[j++];
    }
    return ans;
}

Node *inordertoBST(int s, int e, vector<int> &arr)
{
    if (s > e)
    {
        return NULL;
    }
    int mid = s + (e - s) / 2;
    Node *root = new Node(arr[mid]);
    root->left = inordertoBST(s, mid - 1, arr);
    root->right = inordertoBST(mid + 1, e, arr);

    return root;
}

Node *Merge2BST(Node *r1, Node *r2)
{
    vector<int> arr1;
    vector<int> arr2;
    InOrder(r1, arr1);
    InOrder(r2, arr2);

    vector<int> arr3 = MergeArr(arr1, arr2);
    int s = 0, e = arr3.size() - 1;

    return inordertoBST(s, e, arr3);
}

int main()
{
    Node *r1 = NULL;
    r1 = buildTree(r1);
    Node *r2 = NULL;
    r2 = buildTree(r2);
    // 6 4 2 8 10 -1
    // 5 3 7 9 11 -1
    cout << "Here is tree" << endl;
    InOrder(r1);
    cout << endl;
    InOrder(r2);
    cout << endl;

    cout << "Here is the merge tree:" << endl;
    Node *r3 = Merge2BST(r1, r2);
    InOrder(r3);
    cout << endl;
    return 0;
}