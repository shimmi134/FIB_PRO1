#include <iostream>
#include <vector>

using namespace std;

typedef vector<char> Fila;
typedef vector<Fila> Matriu;

void print_mat(const Matriu &mat)
{
    for (int i = 0; i < mat.size(); i++)
    {
        for (int j = 0; j < mat[0].size(); j++)
        {
            cout << mat[i][j];
        }
        cout << endl;
    }
    cout << endl;
}

Matriu read_vector(int m, int n)
{
    Matriu mat(m,Fila(n));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> mat[i][j];
        }
    }
    return mat;
}

void fires(Matriu& mat, int i, int j)
{
    if (i >= 0 && i < mat.size() && j >= 0 && j < mat[0].size())
    {
        if (mat[i][j] == 'F')
        {
            mat[i][j] = '.';
            if (i > 0 && mat[i-1][j] == 'A') mat[i-1][j] = 'F';
            if (i < mat.size() - 1 && mat[i+1][j] == 'A') mat[i+1][j] = 'F';
            if (j > 0 && mat[i][j-1] == 'A') mat[i][j-1] = 'F';
            if (j < mat[0].size() -1 && mat[i][j+1] == 'A') mat[i][j+1] = 'F';
            fires (mat, i-1, j);
            fires (mat, i+1, j);
            fires (mat, i, j-1);
            fires (mat, i, j+1);
        }
    }
}


int main(void)
{
    int n,m;
    while (cin >> m >> n){
        Matriu mat = read_vector(m,n);
        for (int i = 0; i < mat.size(); i++)
        {
            for (int j = 0; j < mat[0].size(); j++)
            {
                if (mat[i][j] == 'F')
                    fires(mat, i, j);
            }
        }
        print_mat(mat);
        }
}