// here we merge the K sorted array
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

void printArr(vector<int> arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << ' ';
    }
    cout << endl;
}

class Node
{
public:
    int data;
    int rowc, colc;
    Node(int d, int r, int c)
    {
        this->data = d;
        this->rowc = r;
        this->colc = c;
    }
};

class component
{
public:
    bool operator()(Node *a, Node *b)
    {
        return a->data > b->data;
    }
};
vector<int> mergeKArrays(vector<vector<int>> arr, int K)
{
    priority_queue<Node *, vector<Node *>, component> pq;
    for (int i = 0; i < K; i++)
    {
        Node *temp = new Node(arr[i][0], i, 0);
        pq.push(temp);
    }
    vector<int> ans;

    while (!pq.empty())
    {
        Node *top = pq.top();
        pq.pop();
        ans.push_back(top->data);
        int i = top->rowc;
        int j = top->colc;

        if (j + 1 < arr[i].size())
        {
            Node *insert = new Node(arr[i][j + 1], i, j + 1);
            pq.push(insert);
        }
    }
    return ans;
}
int main()
{
    vector<vector<int>> arr = {{1, 2, 3, 4},
                               {2, 2, 3, 4},
                               {5, 5, 6, 6},
                               {7, 8, 9, 9}};
    int k = 4;
    vector<int> ans = mergeKArrays(arr, k);
    printArr(ans);
    return 0;
}