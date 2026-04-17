#include <bits/stdc++.h>
using namespace std;

struct Cell {
    int R, C, V, W;
};

/*
 * Fill in the original array A (length N, each in [1, 10^9])
 * and discards (at most D distinct 1-indexed cell indices). The
 * discards output line will begin with t, the number of discarded
 * cells, followed by those t indices; t is computed and written
 * for you in main().
 *
 * N: length of the array A
 * M: number of cells
 * D: maximum number of cells you may discard
 * cells: vector of M Cells; for cell k (1-indexed), the product
 *        A[R] * A[C] should be close to the target V, with weight W
 */
void solve(int N, int M, int D, const vector<Cell>& cells,
           vector<int>& A, vector<int>& discards) {
    // YOUR CODE HERE
    A.assign(N, 1);
    discards.clear();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M, D;
    cin >> N >> M >> D;
    vector<Cell> cells(M);
    for (int i = 0; i < M; i++) {
        cin >> cells[i].R >> cells[i].C >> cells[i].V >> cells[i].W;
    }

    vector<int> A, discards;
    solve(N, M, D, cells, A, discards);

    for (int i = 0; i < N; i++) {
        if (i > 0) cout << ' ';
        cout << A[i];
    }
    cout << '\n';
    cout << discards.size();
    for (int idx : discards) cout << ' ' << idx;
    cout << '\n';
    return 0;
}
