#include <vector>
#include <iostream>
using namespace std;


vector<double> merge(const vector<double>& v1, const vector<double>& v2)
{
	int n = v1.size();
	int m = v2.size();
	vector<double>merged(n+m);
	int i = 0;
	int j = 0;
	int k = 0;
	while (i < n and j < m){
		if (v1[i] <= v2[j])
		{
			merged[k] = v1[i];
			i++;
		}
		else {
			merged[k] = v2[j];
			j++;
		}
		k++;
	}
	while (i < n)
	{
		merged[k] = v1[i];
		k++;
		i++;
	}
	while (j < m)
	{
		merged[k] = v2[j];
		k++;
		j++;
	}
	return (merged);
}

