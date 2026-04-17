#include <iostream>
#include <vector>

using namespace std;

/**
 * Return the maximal and minimal volume of the shape (in that order)
 *
 * N: max dimensions of shape
 * S1: projection (shadow) in X-Z plane
 * S2: projection (shadow) in Y-Z plane
 */
string solve(int N, vector<string> S1, vector<string> S2) {
    // YOUR CODE HERE
    return "-1 -1";
}

int main() {
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        int N;
        cin >> N;
        vector<string> S1(N);
        for (int i = 0; i < N; i++) {
            cin >> S1[i];
        }
        vector<string> S2(N);
        for (int i = 0; i < N; i++) {
            cin >> S2[i];
        }
        cout << solve(N, S1, S2) << '\n';
    }
}
