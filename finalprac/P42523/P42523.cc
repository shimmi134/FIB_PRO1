#include <iostream>
using namespace std;

int gcd(int a, int b)
{
	if (a == 0)
		return (b);
	else if (b == 0)
		return (a);
	else
	{
		int r = a % b;
		a = b;
		b = r;
		return(gcd(a,b));
	}
}
