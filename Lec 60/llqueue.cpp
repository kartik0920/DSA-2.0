#include "Node.cpp"
class MuQueue
{
private:
    Node *front, *rear;
    int size;

public:
    MuQueue()
    {
        front = rear = NULL;
        size = 0;
    }
    void pop()
    {
        if (rear == NULL)
        {

            cout << "It is underflow" << endl;
            return;
        }
        else
        {
            front = front->next;
            if (front == NULL)
            {
                rear = NULL;
            }
            size--;
        }
    }
    void push(int x)
    {
        size++;
        Node *insert = new Node(x);
        if (rear == NULL)
        {
            front = insert;
            rear = insert;
            return;
        }
        rear->next = insert;
        rear = insert;
    }
    int uqeuesize()
    {
        return size;
    }
    bool isEmpty()
    {
        return rear == NULL ? 1 : 0;
    }
};
int main()
{
    MuQueue q;
    cout << q.isEmpty() << endl;
    q.push(2);
    q.push(2);
    q.push(2);
    q.push(2);
    q.push(2);
    q.pop();
    cout << q.uqeuesize() << endl;
    cout << q.isEmpty() << endl;
    // q.push();
    return 0;
}