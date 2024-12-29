#include <iostream>
#include <vector>

using namespace std;

vector<int> fusionSort(const vector<int>&v, const vector<int>&u)
{
	vector<int>result(v.size()+u.size());

	int i = 0, j = 0, k = 0;
	while (i < v.size() && j < u.size())
	{
		if (v[i] <= u[j])
		{
			result[k] = v[i];
			i++;
		}
		else {
			result[k] = u[j];
			j++;
		}
		k++;
	}
	while (i < v.size())
	{
		result[k] = v[i];
		i++;
		k++;
	}
	while (j < u.size())
	{
		result[k] = u[j];
		k++;
		j++;
	}
	return(result);
}

int main(void)
{
	vector<int>v = {1,3,4,5,6};
	vector<int>u = {3,6,7,10,15};
	vector<int>result = fusionSort(v, u);
	for (int i = 0; i < result.size(); i++)
	{
		cout << result[i];
		if (result.size()-1 > i)
			cout << " ";
	}
	cout << endl;
}
