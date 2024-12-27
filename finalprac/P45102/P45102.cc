#include <iostream>
using namespace std;

int ft_atoi(char c)
{
	return (c-'0');
}

int evaluate()
{
	char c;
	cin >> c;
	if (c == '(')
	{
		int num = evaluate();
		char op;
		cin >> op;
		int num2 = evaluate();
		cin >> c;
		if (op == '+')
			return (num + num2);
		else if (op == '-')
			return (num - num2);
		else 
			return (num * num2);
	}
	return (ft_atoi(c));
}

int main(void)
{
	cout << evaluate() << endl;
	
}
