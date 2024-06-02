#include <bits/stdc++.h>
#include <iostream>
using namespace std;
vector<long long> printFirstNegativeInteger(long long int A[], long long int N, long long int K)
{
    deque<long long> dq;
    vector<long long> ans;
    for (long long i = 0; i < K; i++)
    {
        if (A[i] < 0)
            dq.push_back(i);
    }
    if (dq.size() > 0)
    {
        ans.push_back(A[0]);
    }
    for (long long i = K; i < N; i++)
    {
        if (!dq.empty() && i - dq.front() >= K)
        {
            dq.pop_front();
        }
        if (A[i] < 0)
        {
            dq.push_back(i);
        }
        if (dq.size() > 0)
        {
            ans.push_back(A[dq.front()]);
        }
        else
        {
            ans.push_back(0);
        }
    }
    return ans;
}
int main()
{
    long long A[] = {-8, 2, 3, -6, 10};
    // long long N = A.size();

    return 0;
}