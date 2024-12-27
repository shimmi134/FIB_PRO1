#include <iostream>
using namespace std;

int	main()
{
	// Farem un programa que calculi la mitjana entre 3 notes
	// i dona una medalla en cas que es compleixin unes condicions.
	cout.setf(ios::fixed); // Posa els decimals als floats inclus si no ho necessiten
	cout.precision(2); // El cout ens mostrara dos decimals.
	int	x, y, z;
	float	mitjana;
	cin >> x >> y >> z;
	
	if ((x >= 1 and x <= 10) and (y >= 1 and y <= 10) and (z >= 1 and z <= 10))
	{
		// Calculem la mitjana
		mitjana = ((x + y + z) / 3.0);
		if (x == y and x != z)
		{
			if (x > z)
				mitjana++;
			else
				mitjana--;
		}
		else if (x == z and x != y)
		{
			if (x > y)
				mitjana++;
			else
				mitjana--;
		}
		else if (y == z and y != x)
		{
			if (y > x)
				mitjana++;
			else
				mitjana--;
		}
		if (mitjana >= 9) // Depenent de la mitjana, reben una medalla o una altre.
			cout << "Medalla or" << endl;
		else if (mitjana >= 7)
			cout << "Medalla plata" << endl;
		else if (mitjana >= 5)
			cout << "Medalla bronze" << endl;
		else 
			cout << "Cap premi" << endl;
		cout << mitjana << endl;
		if (x == y and y == z and mitjana >= 5)// Comprovem si x = y = z i ha guanyat medalla, per donar el premi a la unanimitat
			cout << "Premi a la unanimitat" << endl;
	}
}
