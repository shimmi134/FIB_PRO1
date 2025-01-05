#include <iostream>
#include <vector>

using namespace std;

vector<bool>sieve()
{
	long n = 1000000;
	vector<bool> isPrime(n+1,true);
	isPrime[0] = isPrime[1] = false;
	for (long i = 2; i <n; i++)
		if (isPrime[i])
			for (long j = i*i; j <=n; j=j+i)
				isPrime[j] = false;
	return (isPrime);
}
/*
bool bin_search(const vector<long>&p, long n)
{
	long start = 0;
	long end = p.size()-1;
	while (start <= end)
	{
		long mid = start + (end-start)/2;
		if (n == p[mid])
			return (true);
		if (n > p[mid])
			start = mid+1;
		else 
			end = mid-1;
	}
	return (false);
}*/
int main(void)
{
	long n;
	vector<bool>p = sieve();
	while (cin >> n)
	{
		if (p[n])
			cout << n << " is prime";
		else 
			cout << n << " is not prime";
		cout << endl;
	}
}
