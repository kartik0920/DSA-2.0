#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int minCost(int n, vector<int> days, vector<int> cost, int index)
{
    queue<pair<int, int>> month, week;
    int ans = 0;
    for (auto i : days)
    {
        // step 1 clearing expired values
        while (!month.empty() && month.front().first + 30 <= i)
        {
            month.pop();
        }
        while (!week.empty() && week.front().first + 7 <= i)
        {
            week.pop();
        }

        month.push(make_pair(i, cost[2] + ans));
        week.push(make_pair(i, cost[1] + ans));

        ans = min(ans + cost[0], min(month.front().second, week.front().second));
    }
    return ans;
}

int main()
{
    vector<int> days = {2, 5};
    vector<int> cost = {1, 4, 25};
    int n = days.size();
    // space optmized solution

    cout << minCost(n, days, cost, 0) << endl;

    return 0;
}