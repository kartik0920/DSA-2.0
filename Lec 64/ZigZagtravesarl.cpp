#include "Node.cpp"
vector<int> zigZagTraversal(Node *root)
{

    vector<int> ans;
    if (root == NULL)
    {
        return ans;
    }
    bool ltr = 1;
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        int size = q.size();
        vector<int> temp1(size);
        for (int i = 0; i < size; i++)
        {
            Node *temp = q.front();
            q.pop();
            int index = ltr ? i : size - i - 1;
            temp1[index] = temp->data;
            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
        }
        ltr = !ltr;
        for (auto i : temp1)
        {
            ans.push_back(i);
        }
    }
    return ans;
}
void print(vector<int> arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << ' ';
    }
    cout << endl;
}
int main()
{
    Node *root = NULL;
    root = buildTree(root);
    // 1 2 4 -1 -1 5 -1 -1 3 6 -1 -1 7 -1 -1
    cout << "Here is tree" << endl;
    LevelOrder(root);
    cout << "Travesesal is " << endl;
    vector<int> t = zigZagTraversal(root);
    print(t);
    return 0;
}