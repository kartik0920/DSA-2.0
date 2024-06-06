#include "Node.cpp"
void print(vector<int> arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << ' ';
    }
    cout << endl;
}
vector<int> VerticalTraversal(Node *root)
{
    map<int, map<int, vector<int>>> nodes;
    queue<pair<Node *, pair<int, int>>> q;
    vector<int> ans;
    if (root == NULL)
    {
        return ans;
    }
    q.push(make_pair(root, make_pair(0, 0)));

    while (!q.empty())
    {
        pair<Node *, pair<int, int>> temp = q.front();
        Node *FrontNode = temp.first;
        int HoriDis = temp.second.first;
        int lvl = temp.second.second;
        q.pop();
        nodes[HoriDis][lvl].push_back(FrontNode->data);

        if (FrontNode->left)
            q.push({FrontNode->left, {HoriDis - 1, lvl + 1}});
        if (FrontNode->right)
            q.push({FrontNode->right, {HoriDis + 1, lvl + 1}});
    }
    for (auto i : nodes)
    {
        for (auto j : i.second)
        {
            for (auto k : j.second)
                ans.push_back(k);
        }
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
    vector<int> t = VerticalTraversal(root);
    print(t);
    return 0;
}