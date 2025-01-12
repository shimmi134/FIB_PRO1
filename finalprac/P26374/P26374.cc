#include <iostream>
#include <vector>

using namespace std;

typedef vector< vector<int> > Matrix;
 	
Matrix sum(const Matrix& a, const Matrix& b)
{
    Matrix res(a.size(), vector<int>(a.size()));
    for (int i = 0; i < a.size(); i++)
    {
        for (int j = 0; j < a[0].size(); j++)
            res[i][j] = a[i][j] + b[i] [j];
    }
    return (res);    
}