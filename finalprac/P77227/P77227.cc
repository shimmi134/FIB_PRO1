#include <iostream>
#include <vector>

using namespace std;

string exit(int p, vector<int>& v)
{
    int size = v.size();
    int pini;
    while (v[p] != 0 and v[p]+p >= 0 and size > v[p]+p)
    {
        pini = p;
        p = v[p]+p;
        v[pini] = 0;
    }
    if (v[p] == 0) return "never";
    else if (v[p]+p < 0) return "left";
    else return "right";
}
