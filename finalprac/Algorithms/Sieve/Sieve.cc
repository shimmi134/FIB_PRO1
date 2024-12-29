#include <iostream>
#include <vector>

using namespace std;

vector<int> Sieve(int n)
{
	vector<bool>isPrime(n+1,true);
	vector<int>listP;

	for(int i = 2; i <= n; i++)
	{
		if (isPrime[i])
		{
			for (int j = i*i; j <= n; j = j+i)
			{
				isPrime[j] = false;
			}
		}
	}
	for (int i = 2; i <= n; i++)
	{
		if (isPrime[i])
			listP.push_back(i);
	}
	for (int i = 0; i < listP.size(); i++)
	{
		cout << listP[i] << " ";
	}
	cout << endl;
	return (listP);
}


int main(void)
{
	int n;
	while(cin >> n)
	{
		vector<int> p = Sieve(n);
	}
}
