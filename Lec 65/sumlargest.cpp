#include "Node.cpp"
void solve(Node *root, int lvl, int &maxlvl, int sum, int &maxsum)
{
    if (root == NULL)
    {
        if (lvl > maxlvl)
        {
            maxsum = sum;
            maxlvl = lvl;
        }
        else if (lvl == maxlvl)
        {
            maxsum = max(maxsum, sum);
        }
        return;
    }
    sum += root->data;
    solve(root->left, lvl + 1, maxlvl, sum, maxsum);
}
int sumOfLongRootToLeafPath(Node *root)
{
    int lvl = 0, maxlvl = 0;
    int sum = 0, maxsum = 0;
    solve(root, lvl, maxlvl, sum, maxsum);
    return maxsum;
}
int main()
{
    Node *root = NULL;
    root = buildTree(root);
    // 1 2 4 -1 -1 5 -1 -1 3 6 -1 -1 7 -1 -1
    cout << "Here is tree" << endl;
    LevelOrder(root);
    cout << endl;
    cout << "Sum is " << sumOfLongRootToLeafPath(root) << endl;
    return 0;
}