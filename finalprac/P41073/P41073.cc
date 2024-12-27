#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void print_a(vector<int>p)
{
	for (int i = 0; i < p.size(); i++)
		cout << p[i] << " ";
	cout << "\n";

}


int power(int base, int exponent)
{
	int result = 1;
	if (exponent == 0)
		return (result);
	for (int i = 0; i < exponent; i++)
		result = result * base;
	return(result);
}

vector<int> SieveOfEratosthenes(int n)
{
	vector<bool>isPrime(n+1, true);
	vector<int>listPrime;
	for (int i = 2; i * i < n; i++)
	{
		if (isPrime[i])
		{
			for (int j = i*i; j <=n; j= j+i)
				isPrime[j] = false;
		}
	}
	for (int p = 2; p <= n; p++)
        if (isPrime[p])
			listPrime.push_back(p);
	return(listPrime);
}

int main(void)
{
	string str;
	vector<int>p = SieveOfEratosthenes(4*(power(10,6)));
	while (cin >> str)
	{
		long result = 1;
		for (int i = 0; i < str.size(); i++)
		{
			if (str[i] != '0')
				result = result * power(p[i], str[i]-'0');
		}
		cout << str << " -> " << result << endl;
	}
}
