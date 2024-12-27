#include <iostream>
#include <vector>
using namespace std;

vector<double> fusion(const vector<double>& u, const vector<double>& v) {
	int n = u.size();
	int m = v.size();
	vector <double> res(n + m);
	int i = 0;  //indice de u (sennala el menor de u todavia no incorparado)
	int j = 0;  //indice de v (sennala el menor de v todavia no incorparado)
 	int k = 0;  //indice de res (sennala la primera posicion libre de res)
	while (i < n and j < m) {
		if (u[i] <=  v[j]) {
			res[k] = u[i];
			++i;
		}
		else {
			res[k] = v[j];
			++j;
		}
		++k;
	}
	while (i < n) {
		res[k] = u[i];
		++i;
		++k;
	}	
	while (j < m) {
		res[k] = v[j];
		++j;
		++k;
	}
	return res;
}
int main(void)
{
	vector<double>v = {1,2,3,4,5};
	vector<double>u = {2,3,5,7,9};
	vector<double>vect = fusion(v, u);
	for (int i = 0; i < vect.size(); i++)
		cout << vect[i] << " ";
}
