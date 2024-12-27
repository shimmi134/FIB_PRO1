#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> Row;
typedef vector<Row> Matrix;

/*
 * @PRE: A number of rows and columns
 * @POST: A filled matrix of size rows * columns
 * */

void fill_matrix(Matrix& mat, int row, int col)
{
	for (int i = 0; i < row; i++)	
		for(int j = 0; j < col; j++)
			cin >> mat[i][j];
}

/*
 * @PRE: A non empty matrix and the size of the square we'll use to check for alien density;
 * @POST: The position of the matrix where the square of highest density starts, 
 * sum of the densities of the square and the element with highest density
 * */
void get_point(const Matrix& mat, int square)
{
	int max_val = 0, max_sum = 0, x = 0,y = 0;
	for (int i = 0; i < mat.size() - square + 1; i++)
	{
		for (int j = 0; j < mat[0].size() - square + 1; j++)
		{
			int sum = 0;
			int local_max = 0;
			for (int k = 0; k < square; k++)
			{
				for (int m = 0; m < square; m++)
				{
					
					int val = mat[i+k][j+m];
					if (val > local_max)
						local_max = val;
					sum += val;

				}
			}
			if (sum > max_sum)
			{
				max_sum = sum;
				max_val = local_max;
				x = i;
				y = j;
			}
		}
	}
	cout << '(' << x << ',' << y << ')' << endl;
	cout << max_sum << endl << max_val << endl;
}

/*
 * @PRE: The number of rows and columns of a matrix, then the matrix, and then length of the analysis square
 * @POST: ----
 * */
int	main(void)
{
	int row, col, square;
	while (cin >> row >> col && row != 0)
	{
		Matrix mat (row, Row(col));
		fill_matrix (mat,row,col);
		cin >> square;
		get_point(mat, square);
	}
}
