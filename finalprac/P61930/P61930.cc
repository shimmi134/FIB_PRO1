#include <iostream>
using namespace std;

int sum_of_digits(int n)
{
	int num = 0;
	if (n > 9)
		num = sum_of_digits(n/10);
	num = num + n % 10;
	return (num);
}


bool is_multiple_3(int n)
{
	int sum = sum_of_digits(n);
	return(sum % 3 == 0);
}
