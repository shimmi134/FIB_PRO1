#include <iostream>
using namespace std;

int	main() // Programa que, dado un input, nos devuelve si es un
	       // Magic number o no.
{
	
	int	x, len, n, total;

	cin >> x; 
	len = 0;
	total = 0;
	n = x;
	while (n != 0) //Calculamos longitud del numero
	{
		len++; 
		n = n/10;
	}
	n = x;
	while (n != 0) // Hacemos el elevado.
	{
		int	power = 1;
		int	digit = n % 10;
		int	i = 0;
		while (i < len)
		{	
			power *= digit; 
			i++;
		}
		total = total + power; 
		n = n / 10; 
	}
	if (total == x) 
		cout << "strange number: " << x << endl;
	else
		cout << "not strange number: " << x << endl;
}
