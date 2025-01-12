#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Person{
    string name;
    int id;
};

void read_input(vector<Person> &v)
{
    Person p;
    cin >> p.id >> p.name;
    v.push_back(p);
}

int check_repetitions(const vector<Person>&v)
{
    int repetitions = 0;
    int size = v.size();
    for (int i = 0; i < size; i++)
    {
        for (int j = i+1; j < size; j++)
        {
            if (v[i].name == v[j].name and v[i].id == v[j].id) repetitions++;
        }
    }
    return (repetitions);
}

int check_conflicts(const vector<Person>&v)
{
    int conflicts = 0;
    int size = v.size();
    for (int i = 0; i < size; i++)
    {
        for (int j = i; j < size; j++)
        {
            if (v[i].id == v[j].id and v[i].name != v[j].name) conflicts++;
        }
    }
    return conflicts;
}

int check_coincidences (const vector <Person>&v)
{
    int coincidences = 0;
    int size = v.size();
    for (int i = 0; i < size; i++)
    {
        for (int j = i; j < size; j++)
        {
            if (v[i].id != v[j].id and v[i].name == v[j].name) coincidences++;
        }
    }
    return coincidences;
}
/*
bool comp(Person p1, Person p2)
{
    if (p1.id < p2.id) return (true);
    else if (p1.id == p2.id and p1.name < p2.name) return true;
    return false;
}*/
/*
void merge(vector<Person>&v, int s, int e, int m)
{
    int i = s;
    int j = m+1;
    int k = 0;
    vector<Person> temp(e-s+1);
    while (i <=m and j <= e){
        if (v[i].id < v[j].id){
            temp[k] = v[i];
            i++;
        }
        else if (v[i].id == v[j].id){
            if (v[i].name < v[j].name){
                temp[k] = v[i];
                i++;
            }
            else{
                temp[k] = v[j];
                j++;
            }
        }
        else{
            temp[k] = v[j];
            j++;
        }  
        k++; 
    }
    while (i <= m)
    {
        temp[k] = v[i];
        i++;
        k++;
    }
    while (j <= e)
    {
        temp[k] = v[j];
        j++;
        k++;
    }
    for (int t = 0; t < temp.size(); t++)
        v[s+t] = temp[t];
}

void sort(vector<Person>&v, int s, int e)
{
    if (s < e)
    {
        int m = s + (e-s)/2;
        sort(v,s,m);
        sort(v,m+1,e);
        merge(v,s,e,m);
    }
}

void mergeSort(vector<Person>&v)
{
    sort(v,0,v.size()-1);
}
*/
int main(void)
{
    int num;
    
    while (cin >> num)
    {
        vector<Person>v;
        while (num > 0)
        {
            read_input(v);
            num--;
        }
        //mergeSort(v);
        int repetitions = check_repetitions(v);
        int conflicts = check_conflicts(v);
        int coincidences = check_coincidences(v);
        cout << repetitions << " " << conflicts << " " << coincidences << endl;

    }
    
}