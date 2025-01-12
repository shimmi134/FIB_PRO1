#include <cmath>
#include <vector>
using namespace std;

int findDistance(int d, const vector<int>& v) {
    int start = 0;
    int end = v.size() - 2; // We only compare pairs, so we stop at n-2.

    while (start <= end) {
        int m = start + (end - start) / 2;
        int dist = abs(v[m] - v[m + 1]);

        if (dist == d) {
            return m; // Found the matching pair.
        } else if (dist < d) {
            start = m + 1; // Move right since the sequence is increasing.
        } else {
            end = m - 1; // Move left.
        }
    }

    return -1; // No matching distance found.
}
