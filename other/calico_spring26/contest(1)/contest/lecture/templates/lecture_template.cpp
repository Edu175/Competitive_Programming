#include <bits/stdc++.h>
using namespace std;

/*
 * M: number of rows in the lecture hall
 * N: number of columns in the lecture hall
 * K: number of friends who need seats
 * GRID: vector of M strings of length N; '#' is a blocked seat, '-' is an empty seat
 *
 * Return a vector of K (row, col) pairs for the chosen seats.
 */
vector<pair<int, int>> solve(int M, int N, int K, vector<string>& GRID) {
    // YOUR CODE HERE
    return vector<pair<int, int>>(K, {0, 0});
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        int M, N, K;
        cin >> M >> N >> K;
        vector<string> GRID(M);
        for (int i = 0; i < M; i++) {
            cin >> GRID[i];
        }
        vector<pair<int, int>> result = solve(M, N, K, GRID);
        for (auto& p : result) {
            cout << p.first << " " << p.second << "\n";
        }
    }
    return 0;
}
