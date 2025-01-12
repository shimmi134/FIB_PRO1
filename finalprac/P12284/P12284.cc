#include <iostream>
#include <vector>

using namespace std;

struct Parella{
    int freq;
    string par;
};

void add_pair(vector<Parella>&p, string word)
{
    Parella p1;
    p1.freq = 1;
    p1.par = word;
    p.push_back(p1);
}
void sort(vector <Parella>&p, int s, int e, int m)
{
    int i = s;
    int j = m+1;
    int k = 0;
    vector<Parella>temp(e-s+1);
    while (i <=m and j <= e)
    {
        if (p[i].freq > p[j].freq)
        {
            temp[k] = p[i];
            i++;
        }
        else if (p[i].freq == p[j].freq)
        {
            if (p[i].par < p[j].par)
            {
                temp[k] = p[i];
                i++;
            }
            else
            {
                temp[k] = p[j];
                j++;
            }
        }
        else
        {
            temp[k] = p[j];
            j++;
        }
        k++;
    }
    while (i <= m)
    {
        temp[k] = p[i];
        k++;
        i++;
    }
    while (j <= e)
    {
        temp[k] = p[j];
        k++;
        j++;
    }
    for (int t = 0; t < temp.size(); t++)
        p[s+t] = temp[t];
}

void merge(vector<Parella>&p, int s, int e)
{
    if (s < e)
    {
        int m = s + (e-s)/2;
        merge(p,s,m);
        merge(p,m+1,e);
        sort(p,s,e,m);
    }
}

void mergeSort(vector<Parella>&p)
{
    merge(p,0,p.size()-1);
}

int main(void)
{
    int size, top;
    while (cin >> size >> top)
    {
        vector<Parella>p;
        string word;
        
        for (int i = 0; i < size; i++)
        {
            bool found = false;
            cin >> word;
            if (p.size() == 0)
                add_pair(p,word);
            else
            {
                for (int j = 0; j < p.size() && !found; j++)
                {
                    if (word == p[j].par)
                    {
                        p[j].freq++;
                        found = true;
                    }
                }
                if (!found)
                    add_pair(p,word);
            }
        }
        mergeSort(p);
        for (int i = 0; i < top; i++)
            cout << p[i].par << endl;
        cout << "----------" << endl;
    }
}