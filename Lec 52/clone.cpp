// Approach 1
class Solution
{
private:
    void insert(Node *&tail, int data)
    {
        Node *temp = new Node(data);
        tail->next = temp;
        tail = tail->next;
    }

public:
    Node *copyRandomList(Node *head)
    {
        Node *clonehead = new Node(-1);
        Node *clonetail = clonehead;

        // step 1: copy LL
        Node *temp1 = head;
        while (temp1 != NULL)
        {
            insert(clonetail, temp1->val);
            temp1 = temp1->next;
        }
        clonehead = clonehead->next;
        // step 2: Map all element
        unordered_map<Node *, Node *> mapping;
        temp1 = head;
        Node *temp2 = clonehead;
        while (temp1 != NULL)
        {
            mapping[temp1] = temp2;
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        // step 3;
        temp1 = head, temp2 = clonehead;
        while (temp1 != NULL)
        {
            temp2->random = mapping[temp1->random];
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        return clonehead;
    }
};

// Approach 2

class Solution
{
private:
    void insert(Node *&tail, int data)
    {
        Node *temp = new Node(data);
        tail->next = temp;
        tail = tail->next;
    }

public:
    Node *copyRandomList(Node *head)
    {
        Node *clonehead = new Node(-1);
        Node *clonetail = clonehead;

        // step 1: copy LL
        Node *temp1 = head;
        while (temp1 != NULL)
        {
            insert(clonetail, temp1->val);
            temp1 = temp1->next;
        }
        clonehead = clonehead->next;
        // step 2: Map all element to next pointer
        Node *on = head, *cn = clonehead;
        while (on != NULL && cn != NULL)
        {
            Node *next = on->next;
            on->next = cn;
            on = next;
            next = cn->next;
            cn->next = on;
            cn = next;
        }

        // step 3 copy random
        Node *temp = head;
        while (temp != NULL)
        {
            if (temp->next != NULL)
            {
                temp->next->random =
                    temp->random ? temp->random->next : temp->random;
            }
            temp = temp->next->next;
        }
        // step 4 revert
        on = head, cn = clonehead;
        while (on != NULL && cn != NULL)
        {
            on->next = cn->next;
            on = on->next;
            if (on != NULL)

            {
                cn->next = on->next;
                cn = on->next;
            }
        }
        return clonehead;
    }
};