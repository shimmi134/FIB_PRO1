//#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

// Pre: Let n be v.size(). n>=2 and d>=0 and |v[0]-v[1]| < |v[1]-v[2]| < ... < |v[n-2]-v[n-1]|
// Post: If there exists i in {0..n-2} holding |v[i]-v[i+1]| = d, then the function returns this i.
//       Otherwise, it returns -1.
int findDistance(int d, const vector<int> &v)
{
	for (int i = 0; i < v.size()-1; i++)
	{
		if (abs(v[i]-v[i+1]) > d)
			return (-1);
		if (abs(v[i]-v[i+1]) == d)
			return (i);
	}
	return (-1);
}
/*
int main(void)
{
	cout << findDistance(2, {7, 8, 10, 5}) << endl;
	cout << findDistance(12, {7, 9, 16, 8, -4, 9, 25}) << endl;
	cout << findDistance(11, {8, 12, 19, 30, 46, 27}) << endl;
	cout << findDistance(36, {1, 5, 10, 1, -9, -21, -8, -24, -41, -63, -38, -64, -91, -121, -156, -120, -80, -124}) << endl;
	cout << findDistance(32, {2, 1, -1, -7, 2, -9, -25, -8, -29, -6, 20, 49, 18, 50, 16, 55}) << endl;
	cout << findDistance(69, {9, 6, 12, 1, 13, 26, 42, 63, 41, 68, 36, 1, -37, 2, -41, 5, -46, 7}) << endl;
}*/
