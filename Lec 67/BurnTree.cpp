#include "Node.cpp"
Node *CreateMap(map<Node *, Node *> &ChildToParent, Node *root, int target)
{
    Node *res = NULL;
    queue<Node *> q;
    q.push(root);
    ChildToParent[root] = NULL;
    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        if (temp->data == target)
        {
            res = temp;
        }
        if (temp->left)
        {
            ChildToParent[temp->left] = temp;
            q.push(temp->left);
        }
        if (temp->right)
        {
            ChildToParent[temp->right] = temp;
            q.push(temp->right);
        }
    }
    return res;
}
void BurnTree(Node *root, map<Node *, Node *> &ChildToParent, int &ans)
{
    map<Node *, bool> visited;
    queue<Node *> q;
    q.push(root);
    visited[root] = 1;
    while (!q.empty())
    {
        int size = q.size();
        bool flag = 0;
        for (int i = 0; i < size; i++)
        {
            Node *temp = q.front();
            q.pop();
            if (temp->left && !visited[temp->left])
            {
                flag = 1;
                visited[temp->left] = 1;
                q.push(temp->left);
            }
            if (temp->right && !visited[temp->right])
            {
                flag = 1;
                visited[temp->right] = 1;
                q.push(temp->right);
            }
            Node *parent = ChildToParent[temp];
            if (parent && !visited[parent])
            {
                flag = 1;
                visited[parent] = 1;
                q.push(parent);
            }
           
        }
         if (flag)
            {
                ans++;
            }
    }
}
int minTime(Node *root, int target)
{
    int ans = 0;
    map<Node *, Node *> ChildToParent;
    Node *targetNode = CreateMap(ChildToParent, root, target);
    BurnTree(targetNode, ChildToParent, ans);
    return ans;
}
int main()
{
    Node *root = NULL;
    root = CreateLevel(root);
    // 1 2 4 -1 -1 5 -1 -1 3 6 -1 -1 7 -1 -1
    cout << "Here is tree" << endl;
    // LevelOrder(root);
    cout << minTime(root, 8) << endl;
    return 0;
}
