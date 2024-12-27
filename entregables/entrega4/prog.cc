#include <iostream>
using namespace std;

//Pre: Una sequencia en binari
//Post: La sequencia en base decimal

int	main()
{	
	int sum = 0;
	int	result = 0;
	int counter = 0;
	char c, d;
	while (cin >> c >> d)
	{
		if (c == d)
		{
			sum = 2*sum + (c - '0');
			counter = 0;
		}
		else
		{
			result = result + sum;
			sum = 0;
			counter++;
		}
		if (counter == 2)
		{
			cout << result << endl;
			result = 0;
			counter = 0;
		}
	}
}
