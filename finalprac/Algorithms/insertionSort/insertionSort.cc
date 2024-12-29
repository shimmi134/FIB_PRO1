#include <iostream>
#include <vector>

using namespace std;

void insertion_sort(vector<double>& v)
{
	for (int i = 1; i < v.size(); i++)
	{
		double first = v[i];
		int j = i - 1;
		while (j >= 0 && v[j] > first)
		{
			v[j+1] = v[j];
			j--;
		}
		v[j+1] = first;
	}
}
/*
void print_vector(const vector<double>&u)
{
	for (int i = 0; i < u.size(); i++)
	{
		cout << u[i];
		if (i != u.size()-1)
			cout << " ";
	}
	cout << '\n';
}

int main(void)
{
	int n;
	cin >> n;
	vector<double>u(n);
	for (int i = 0; i < n; i++)
		cin >> u[i];
	print_vector(u);
	insertionSort(u);
	print_vector(u);
}*/
