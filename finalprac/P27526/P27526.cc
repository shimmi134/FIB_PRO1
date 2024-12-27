#include <iostream>
#include <vector>

using namespace std;
typedef vector<int> Fila;
typedef vector<Fila> Matrix;

void swap(Matrix& mat, int j, int k)
{
	int x = mat.size();
	for (int i = 0; i < x; i++)
	{
		int temp = mat[i][j];
		mat[i][j] = mat[i][k];
		mat[i][k] = temp;
	}
}

void print_matrix(Matrix& m)
{
	int x = m.size();
	int y = m[0].size();
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			cout << m[i][j];
			if (j != y-1)
				cout << " ";
		}
		cout << '\n';
	}
}

void read_matrix(Matrix& m)
{
	int x = m.size();
	int y = m[0].size();
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
			cin >> m[i][j];
	}
}

int main(void)
{
	int n, m;
	cin >> n >> m;
	Matrix mat(n,Fila(m));
	read_matrix(mat);
	cout << "-----" << endl;
	print_matrix(mat);
	cout << "-----" << endl;
	while (cin >> n >> m)
	{
		swap(mat,n,m);
		print_matrix(mat);
		cout << "-----" << endl;
	}
}
