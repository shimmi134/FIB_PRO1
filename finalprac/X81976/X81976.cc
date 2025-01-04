#include <iostream>
#include <vector>
#include <string>
using namespace std;

typedef vector<int> Fila;
typedef vector<Fila> Matrix;

int main () {
    int n, m;
    while (cin >> n >> m) {
        vector<string> u(n);
        for (int i = 0; i < n; ++i) {
            cin >> u[i];
        }
        Matrix row_freq(n, Fila(10, 0));
        Matrix col_freq(m, Fila(10, 0));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                int digit = u[i][j] - '0';
                row_freq[i][digit]++;
                col_freq[j][digit]++;
            }
        }
        Matrix v(n, Fila(m, 0));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                int digit = u[i][j] - '0';
                v[i][j] = (row_freq[i][digit] + col_freq[j][digit]) % 10;
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cout << v[i][j];
            }
            cout << endl;
        }
        cout << endl;
    }
}

