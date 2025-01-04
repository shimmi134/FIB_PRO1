#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> Fila;
typedef vector<Fila> Matriu;

void read_matrix(Matriu& mat)
{
	for (int i = 0; i < mat.size(); i++)
		for (int j = 0; j < mat[0].size(); j++)
			cin >> mat[i][j];
}

int main(void)
{
	int n,m, count = 1;
	while (cin >> n >> m)
	{
		bool isCorrect = true;
		int i = 0;
		Matriu mat(n,Fila(m));
		read_matrix(mat);
		while (i < mat[0].size() and isCorrect)
		{
			int j = 0;
			while (j < mat.size()-1 and isCorrect)
			{
				if (mat[j][i] >= mat[j+1][i])
					isCorrect = false;
				j++;
				
			}
			if (i+1 != mat[0].size() and mat[j][i] >= mat[j][i+1])
				isCorrect = false;
			i++;
			while (0 < j and isCorrect and i != mat[0].size())
			{
				if (mat[j][i] >= mat[j-1][i])
					isCorrect = false;
				j--;
			}
			if (i+1 < mat[0].size() and mat[j][i] >= mat[j][i+1])
				isCorrect = false;
			i++;
		}
		cout << "matriu " << count << ": ";
		if (isCorrect)
			cout << "yes";
		else
			cout << "no";
		cout << endl;
		count++;

	}
}
