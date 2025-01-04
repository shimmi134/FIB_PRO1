#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool comp(int a, int b)
{
	return (a > b);
}

void print_vect(const vector<int>vect)
{
	for(int i = 0; i < vect.size(); i++)
	{
		cout << vect[i];
		if (i != vect.size()-1)
			cout << " ";
	}
	cout << endl;
}
int main(void)
{
	int n;
	while (cin >> n)
	{
		vector<int>v;
		vector<int>u;
		while (n != 0)
		{
			if (n % 2 == 0)
				v.push_back(n);
			else
				u.push_back(n);
			cin >> n;
		}
		sort(v.begin(), v.end());
		sort(u.begin(), u.end(), comp);
		print_vect(v);
		print_vect(u);
	}
}
