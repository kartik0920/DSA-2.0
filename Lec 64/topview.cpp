#include "Node.cpp"
void print(vector<int> arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << ' ';
    }
    cout << endl;
}
vector<int> LeftView(Node *root)
{
    vector<int> ans;
    if (root == NULL)
    {
        return ans;
    }
    // mapping horizontal distance and elemet
    map<int, int> mapping;
    // queue for Node and horiozntal distance
    queue<pair<Node *, int>> q;
    q.push(make_pair(root, 0));
    while (!q.empty())
    {
        pair<Node *, int> temp = q.front();
        Node *frontnode = temp.first;
        int hd = temp.second;
        q.pop();
        if (mapping.find(hd) == mapping.end())
        {
            mapping[hd] = frontnode->data;
        }
        if (frontnode->left)
            q.push(make_pair(frontnode->left, hd - 1));
        if (frontnode->right)
            q.push(make_pair(frontnode->right, hd + 1));
    }
    for (auto i : mapping)
    {
        ans.push_back(i.second);
    }
    return ans;
}
int main()
{
    Node *root = NULL;
    root = buildTree(root);
    // 1 2 4 -1 -1 5 -1 -1 3 6 -1 -1 7 -1 -1
    cout << "Here is tree" << endl;
    LevelOrder(root);
    cout << "Travesesal is " << endl;
    vector<int> t = LeftView(root);
    print(t);
    return 0;
}