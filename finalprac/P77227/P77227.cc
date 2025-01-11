#include <iostream>
#include <vector>

using namespace std;

string exit(int p, vector<int>& v)
{
    if (v[p] == 0 || p == 0)
        return ("never");
    if (p >= v.size())
        return ("right");
    if (p < 0)
        return ("left");
    if (v[p] > 0)
    {
        if (p + v[p] >= v.size())
            return ("right");
        else
            return exit(p+v[p],v);
    }
    else
    {
        if (p + v[p] < 0)
            return ("left");
        else
            return (exit(p-v[p],v));
    }
}