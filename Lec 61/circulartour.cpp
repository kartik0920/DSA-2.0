#include <bits/stdc++.h>
#include <iostream>
using namespace std;
class petrolPump
{
public:
    int distance, petrol;
};
int tour(petrolPump p[], int n)
{
    int kmi = 0, bal = 0, start = 0;
    for (int i = 0; i < n; i++)
    {
        bal = bal + p[i].petrol - p[i].distance;
        if (bal < 0)
        {
            kmi = kmi + bal;
            start = i + 1;
            bal = 0;
        }
    }
    if (kmi + bal >= 0)
    {
        return start;
    }
    else
    {
        return -1;
    }
    //   return bal;
}
int main()
{

    return 0;
}