#include <iostream>
#include <vector>

using namespace std;
void merge(vector<double>& V, int s, int m, int e)
{
	int i = s;
	int j = m+1;
	int k = 0;
	vector<double>temp(e - s + 1,0);
	while (i <= m  && j <= e)
	{
		if (V[i] < V[j])
		{
			temp[k] = V[i];
			i++;
		}
		else {
			temp[k] = V[j];
			j++;
		}
		k++;
	}
	while (i <= m )
	{
		temp[k] = V[i];
		i++;
		k++;
	}
	while (j <= e)
	{
		temp[k] = V[j];
		j++;
		k++;
	}
	for (int t = 0; t < temp.size(); t++)
		V[s+t] = temp[t];
}

void Sort(vector<double>& V, int s, int e)
{
	if (s < e)
	{
		int m = s + (e-s)/2;
		Sort(V,s,m);
		Sort(V,m+1,e);
		merge(V,s,m,e);
	}
}

void mergesort(vector<double>& V)
{
	Sort(V, 0,V.size()-1);
}
/*
#include <iomanip>
#include <iostream>
#include <vector>


int main()
{
    cout << fixed << setprecision(1);
    int n;
    while (cin >> n) {
        vector<double> v(n);
        for (int i = 0; i < n; ++i) {
            cin >> v[i];
        }
        mergesort(v);
        for (int i = 0; i < n; ++i) {
            cout << " " << v[i];
        }
        cout << endl;
    }
    return 0;
}*/	
