#include <iostream>
using namespace std;

//Pre: 2 ints
//Post: The maximum of the two

int	max(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

//Pre: 2 ints
//Post: The minimum of the two

int	min(int a, int b)
{
	if (a > b)
		return (b);
	else
		return (a);
}

//Pre: A string
//Post: An int

int	ft_atoi(string str)
{
	int result = 0;
	for (int i = 0; i < str.size(); i++)
	{
		result = result * 10 + (str[i] - '0');
	}
	return (result);
}

//Pre: .......
//Post: Max-min evaluation. Returns the number or max/min of two numbers

int	mmeval()
{
	string str;
	cin >> str;
	if (str == "max")
		return (max(mmeval(),mmeval()));
	else if (str == "min")
		return (min(mmeval(),mmeval()));
	else
		return (ft_atoi(str));
}

int main() {
    int num_expressions;
    cin >> num_expressions;
    for (int i = 0; i < num_expressions; i++) {
        cout << mmeval() << endl;
    }
    return 0;
}
