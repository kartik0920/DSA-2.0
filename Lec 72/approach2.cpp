#include "Node.cpp"

void ConvertBST(Node *&head, Node *root)
{
    if (root == NULL)
    {
        return;
    }

    ConvertBST(head, root->right);

    root->right = head;
    if (head != NULL)
    {
        root->left = head;
    }
    head = root;

    ConvertBST(head, root->left);
}

Node *merge(Node *head1, Node *head2)
{
    Node *head = new Node(-1);
    Node *tail = head;

    while (head1 != NULL && head2 != NULL)
    {
        if (head1->data < head2->data)
        {
            tail->right = head1;
            head1->left = tail;
            tail = head1;
            head1 = head1->right;
        }
        else
        {
            tail->right = head2;
            head2->left = tail;
            tail = head2;
            head2 = head2->right;
        }
    }
    while (head1 != NULL)
    {
        tail->right = head1;
        head1->left = tail;
        tail = head1;
        head1 = head1->right;
    }
    while (head2 != NULL)
    {
        tail->right = head2;
        head2->left = tail;
        tail = head2;
        head2 = head2->right;
    }
    // if(head1->right != NULL)
    head = head->right;
    return head;
}

int count(Node *head)
{
    int cnt = 0;
    while (head != NULL)
    {
        head = head->right;
        cnt++;
    }
    return cnt;
}

Node *LLToBST(Node *head, int n)
{
    if (head == NULL)
    {
        return NULL;
    }
    if (n <= 0)
    {
        return NULL;
    }

    Node *leftpart = LLToBST(head->left, n / 2);
    Node *root = head;
    head->left = leftpart;

    head = head->right;

    root->right = LLToBST(head, n - n / 2 - 1);

    return root;
}

Node *Merge2BST(Node *r1, Node *r2)
{
    Node *head1 = NULL, *head2 = NULL;
    ConvertBST(head1, r1);
    ConvertBST(head2, r2);
    head1->left = NULL;
    head2->left = NULL;
    InOrder(head1);
    Node *head = merge(head1, head2);
    int n = count(head);
    return LLToBST(head, n);
    ;
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