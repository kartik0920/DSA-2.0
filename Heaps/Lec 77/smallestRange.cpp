#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Node
{
public:
    int data, i, j;
    Node(int d, int i, int j)
    {
        this->data = d;
        this->i = i;
        this->j = j;
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

int solve(vector<vector<int>> arr, int n)
{
    priority_queue<Node *, vector<Node *>, compare> minHeap;
    int maxi = INT_MIN, mini = INT_MAX;

    // adding in priority QUEUE
    for (int i = 0; i < arr.size(); i++)
    {
        int element = arr[i][0];
        Node *temp = new Node(element, i, 0);
        minHeap.push(temp);
        mini = min(mini, element);
        maxi = max(maxi, element);
    }
    // Initialized answer
    int start = mini, end = maxi;

    while (!minHeap.empty())
    {
        Node *temp = minHeap.top();
        minHeap.pop();

        int i = temp->i, j = temp->j;
        mini = temp->data;

        if (maxi - mini < end - start)
        {
            start = mini;
            end = maxi;
        }
        if (j < n)
        {
            int element = arr[i][j + 1];
            maxi = max(maxi, element);
            Node *temp = new Node(element, i, j + 1);
            minHeap.push(temp);
        }
        else
        {
            return end - start + 1;
        }
    }
    return -1;
}

int main()
{
    vector<vector<int>> arr = {
        {1, 10, 11},
        {2, 3, 20},
        {5, 6, 12}};

    int n = arr[0].size();
    cout << solve(arr, n) << endl;
    return 0;
}