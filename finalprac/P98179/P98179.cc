#include <iostream>
#include <vector>

using namespace std;

void insert(vector<double>& v)
{
	for (int i = 0; i < v.size(); i++)
	{
		if (v[i] >= v[v.size()-1])
		{
			double temp = v[i];
			v[i] = v[v.size()-1];
			v[v.size()-1] = temp;
		}
	}
}
/*
int main()
{
    cout.setf(ios::fixed, ios::floatfield);
    cout.precision(4);
    int n;
    while (cin >> n) {
        vector<double> V(n);
        for (int i = 0; i < n; ++i) {
            cin >> V[i];
        }
        insert(V);
        for (int i = 0; i < n; ++i) {
            cout << " " << V[i];
        }
        cout << endl;
    }
    return 0;
}*/
