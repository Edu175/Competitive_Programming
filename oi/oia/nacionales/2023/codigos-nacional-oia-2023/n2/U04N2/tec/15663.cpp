#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> board;

void tablero(int N, vector<int>& A, vector<int>& B) {
    board.resize(N + 1, {});
    for (int i = 0; i < A.size(); i++) {
        board[A[i]].push_back(B[i]);
        board[B[i]].push_back(A[i]);
    }
}

int con_quien_comercio(vector<int>& possibles) {
    for (int possible : possibles) {
        for (int x : board[possible]) {
            if (find(possibles.begin(), possibles.end(), x) == possibles.end()) {
                return x;
            }
        }
    }

    return -1;
}
