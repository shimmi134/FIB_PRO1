#include <iostream>
#include <vector>

using namespace std;

vector<int> sieveOfEras(int n)
{
	vector<bool>isPrime(n+1,true);
	vector<int>listPrime;
	for (int i = 2; i * i <= n; i++)
	{
		if (isPrime[i])
		{
			for (int j = i*i; j <= n; j = j+i)
				isPrime[j] = false;
		}
	}
	for (int i = 2; i < isPrime.size(); i++)
		if (isPrime[i])
			listPrime.push_back(i);
	return (listPrime);
}

int main(void)
{
	vector<int>p = sieveOfEras(7919);
	int n;
	while (cin >> n)
	{
		for (int i = 0; i < n; i++)
		{
			cout << p[i];
			if (i < n-1)
				cout <<',';
		}
		cout << endl;
	}
}
