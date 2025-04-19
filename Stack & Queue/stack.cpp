#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Stack
{
    vector<int> arr;
    int top;

public:
    Stack()
    {
        top = -1;
    }
    bool empty()
    {
        return arr.size() == 1 ? 0 : 1;
    }

    void push(int a)
    {
        arr.push_back(a);
        top++;
    }

    int showTop()
    {
        if (top < 0)
        {
            cout << "Empty Stack!";
            return -1;
        }
        return arr[top];
    }

    void pop()
    {
        if (top < 0)
        {
            cout << "Already empty array ";
            return;
        }
        top--;
    }
};

int main()
{
    Stack st;
    cout << st.empty() << endl;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);

    cout << st.showTop() << endl;
    cout << st.empty() << endl;
    st.pop();
    st.pop();
    st.pop();
    cout << st.showTop() << endl;
    st.pop();
    st.pop();

    return 0;
}