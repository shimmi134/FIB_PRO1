#include <iostream>
#include <vector>
using namespace std;

int position(double x, const vector<double>& v, int left, int right)
{
	while (left <= right)
	{
		int m =left + (right-left)/2;
		if (x == v[m])
			return (m);
		else if (x > v[m])
			left = m+1;
		else 
			right = m-1;
	}
	return (-1);
}

