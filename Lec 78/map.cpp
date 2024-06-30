#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int main()
{
    // insertion deletion search in O(1) time coplexity
    unordered_map<int, int> m1;

    // insertion deletion search in O(log n) time complexity
    map<int, int> m2;

    // insertion in map
    pair<int, int> p1 = make_pair(1, 1);
    m1.insert(p1);
    m2.insert(p1);

    pair<int, int> p2(2, 3);
    m1.insert(p2);
    m2.insert(p2);

    m1[3] = 3;
    m2[3] = 3;

    // every key will be unique
    // accesing element
    // if absent will create new elemt with 0 value
    cout << m1[1] << endl;
    // if absent will give error
    cout << m1.at(1) << endl;

    cout << "size of m1 is" << m1.size() << endl;
    // to check presence we use count
    cout << "2 is present or not" << m1.count(2) << endl;
    cout << "6 is present or not" << m1.count(6) << endl;

    // Travesting in maps
    cout << "For unordered map" << endl;
    for (auto i : m1)
    {
        cout << i.first << '=' << i.second << endl;
    }
    cout << "For ordered map" << endl;
    for (auto i : m2)
    {
        cout << i.first << '=' << i.second << endl;
    }

    // using iterator
    unordered_map<int, int>::iterator it = m1.begin();
    cout << "Using iterator" << endl;
    while (it != m1.end())
    {
        cout << it->first << " " << it->second << endl;
        it++;
    }

    return 0;
}