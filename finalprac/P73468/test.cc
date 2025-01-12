#include <iostream>
#include <vector>
using namespace std;

typedef vector<vector<char> > Matriu;

// Function to read the forest matrix
Matriu read_forest(int n, int m) {
    Matriu mat(n, vector<char>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> mat[i][j];
        }
    }
    return mat;
}

// Function to print the forest matrix
void print_forest(const Matriu &mat)
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

// Recursive function to spread fire
void spread_fire(Matriu& mat, int i, int j) {
    // Check boundaries and valid fire positions
    if (i < 0 || i >= mat.size() || j < 0 || j >= mat[0].size()) return;
    if (mat[i][j] != 'F') return;

    // Burn the current tree
    mat[i][j] = '.';

    // Spread fire in all four directions
    if (i > 0 && mat[i-1][j] == 'A') mat[i-1][j] = 'F';
    if (i < mat.size() - 1 && mat[i+1][j] == 'A') mat[i+1][j] = 'F';
    if (j > 0 && mat[i][j-1] == 'A') mat[i][j-1] = 'F';
    if (j < mat[0].size() - 1 && mat[i][j+1] == 'A') mat[i][j+1] = 'F';

    // Recursively spread fire to adjacent positions
    spread_fire(mat, i-1, j);
    spread_fire(mat, i+1, j);
    spread_fire(mat, i, j-1);
    spread_fire(mat, i, j+1);
}

int main() {
    int n, m;
    while (cin >> n >> m) {
        Matriu forest = read_forest(n, m);

        // Spread fire for each burning tree in the forest
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (forest[i][j] == 'F') {
                    spread_fire(forest, i, j);
                }
            }
        }

        // Print the final state of the forest
        print_forest(forest);
    }
    return 0;
}

