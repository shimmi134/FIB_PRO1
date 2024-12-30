#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct person{
    string name;
    int age;
};

void merge(vector<person> &v, int s, int m, int e)
{
    int i = s;
    int j = m+1;
    int k = 0;
    vector<person> temp(e-s+1);
    while (i <= m && j <= e)
    {
        if (v[i].age < v[j].age or (v[i].age == v[j].age && v[i].name > v[j].name))
        {
            temp[k].age = v[i].age;
			temp[k].name = v[i].name;
            i++;
        }
        else
        {
            temp[k].age = v[j].age;
			temp[k].name = v[j].name;
            j++;
        }
        k++;
    }
    while (i <=m)
    {
        temp[k].age = v[i].age;
		temp[k].name = v[i].name;
        k++;
        i++;
    }
    while (j <= e)
    {
        temp[k].age = v[j].age;
        temp[k].name = v[j].name;
        k++;
        j++;
    }
    for (int t = 0; t < temp.size(); t++)
	{
        v[s+t].age = temp[t].age;
		v[s+t].name = temp[t].name;
	}
}

void mergeSort(vector<person>& v, int s, int e)
{
    if (e > s)
    {
        int m = s + (e-s)/2;
        mergeSort(v,s,m);
        mergeSort(v,m+1,e);
        merge(v,s,m,e);
    }
}

void read_vector(vector<person>&v, int n)
{
	int i = 0, edat;
	string nom;
	while (i < n)
    {
        cin >> nom >> edat;
        v[i].name = nom;
        v[i].age = edat;
		i++;
    }
}

int main(void)
{
    int n;
    string nom; 
    cin >> n;
    vector<person>v(n);
	read_vector(v, n);
    mergeSort(v,0,v.size()-1);
    for (int j = v.size()-1; j >= 0; j--)
        cout << v[j].name << " " << v[j].age << endl;

}
