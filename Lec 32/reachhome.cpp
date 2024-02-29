#include <iostream>
using namespace std;

void reachHome(int src, int dest)
{
    cout << src << " " << dest << endl;
    if (src == dest)
    {
        cout << "aa gye" << endl;
        return;
    }

    reachHome(++src, dest);
}
int main()
{
    int src = 1, dest = 10;
    reachHome(src, dest);
    return 0;
}