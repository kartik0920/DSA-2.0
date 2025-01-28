#include <bits/stdc++.h>
#include <iostream>
using namespace std;

void printArr(vector<int> arr)
{
    for (auto i : arr)
    {
        cout << i << " ";
    }
    cout << endl;
}

class Node
{
public:
    int data, row, col;
    Node(int data, int i, int j)
    {
        this->data = data;
        this->row = i;
        this->col = j;
    }
};

class compare
{
public:
    bool operator()(Node *a, Node *b)
    {
        return a->data > b->data;
    }
};

vector<int> mergeArray(vector<vector<int>> arr, int k)
{
    priority_queue<Node *, vector<Node *>, compare> pq;
    // Adding first element in pq
    for (int i = 0; i < k; i++)
    {
        Node *temp = new Node(arr[i][0], i, 0);
        pq.push(temp);
    }
    vector<int> ans;

    while (!pq.empty())
    {
        Node *temp = pq.top();
        pq.pop();

        int i = temp->row;
        int j = temp->col;

        ans.push_back(temp->data);

        if (j + 1 < arr[i].size())
        {
            Node *temp = new Node(arr[i][j + 1], i, j + 1);
            pq.push(temp);
        }
    }
    return ans;
}

int main()
{
    vector<vector<int>> arr = {
        {3, 5, 9},
        {1, 2, 3, 8},
    };
    int k = arr.size();
    vector<int> ans = mergeArray(arr, k);
    printArr(ans);
    return 0;
}