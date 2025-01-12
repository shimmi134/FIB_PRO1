#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

// Pre: Let n be v.size(). n>=2 and d>=0 and |v[0]-v[1]| < |v[1]-v[2]| < ... < |v[n-2]-v[n-1]|
// Post: If there exists i in {0..n-2} holding |v[i]-v[i+1]| = d, then the function returns this i.
//       Otherwise, it returns -1.
/*int findDistance(int d, const vector<int> &v)
{
	for (int i = 0; i < v.size()-1; i++)
	{
		if (abs(v[i]-v[i+1]) > d)
			return (-1);
		if (abs(v[i]-v[i+1]) == d)
			return (i);
	}
	return (-1);
}*/

int findDistance (int d, const vector<int> &v)
{
	int start = 0;
	int end = v.size()-2;
	while (start <= end)
	{
		int m = start + (end-start)/2;
		if (abs(v[m]-v[m+1]) == d)
			return m;
		else if (abs(v[m]-v[m+1]) < d)
			start = m+1;
		else 
			end = m-1;
		//cout << "m: " << m << " v[m] " << v[m] <<" v[m+]: " << abs(v[m]-v[m+1]) << " v[m-]: " << abs(v[m]-v[m-1]) <<endl;
	}
	return (-1);
}
/*
int main(void)
{
	cout << findDistance(1, {8, 7,10}) << endl;
	cout << findDistance(12, {7, 9, 16, 8, -4, 9, 25}) << endl;
	cout << findDistance(11, {8, 12, 19, 30, 46, 27}) << endl;
	cout << findDistance(36, {1, 5, 10, 1, -9, -21, -8, -24, -41, -63, -38, -64, -91, -121, -156, -120, -80, -124}) << endl;
	cout << findDistance(32, {2, 1, -1, -7, 2, -9, -25, -8, -29, -6, 20, 49, 18, 50, 16, 55}) << endl;
	cout << findDistance(69, {9, 6, 12, 1, 13, 26, 42, 63, 41, 68, 36, 1, -37, 2, -41, 5, -46, 7}) << endl;
}*/
