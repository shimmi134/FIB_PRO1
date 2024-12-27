#include <iostream>
#include <vector>
using namespace std;

/*
 *
 * @PRE A vector of integers
 * @POST True if all positions of the vector are 10, false otherwise
 *
 * */

bool is_vector_ds(const vector<int>& v)
{
	for (int i = 0; i < v.size(); i++)
		if (v[i] != 10)
			return (false);
	return (true);
}

/*
 *
 * @PRE First a number n. Then a matrix of n x n, with numbers.
 * @POST Prints true if the array is double stochastic, false otherwise.
 *
 * */

int	main()
{
	int num;
	while (cin >> num)
	{
		bool is_ds = true;
		int n;
		int i = 0;
		vector<int> v(num);
		while (i < num)
		{
			int res = 0;
			int j = 0;
			while (j < num)
			{
				cin >> n;
				res = res + n;
				v[j] = v[j]+n;
				j++;
			}
			if (res != 10)
				is_ds = false;
			i++;
		}
		if (not is_vector_ds(v))
			is_ds = false;
		if (is_ds)
			cout << "true" << endl;
		else
			cout << "false" << endl;
	}
}
