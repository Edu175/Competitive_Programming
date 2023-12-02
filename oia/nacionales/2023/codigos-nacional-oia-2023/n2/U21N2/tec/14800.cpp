#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> t;

void tablero(int N, vector<int> &A, vector<int> &B) {
    t = vector<vector<int>>(N+1);
    int M = A.size();
    for (int i = 0; i < M; ++i)
    {
        t[A[i]].push_back(B[i]);
        t[B[i]].push_back(A[i]);
    }
}

int con_quien_comercio(vector<int> &controlados) {
    vector<bool> controla(t.size());
    for (auto c : controlados)
        controla[c] = true;

    for (auto c : controlados)
        for (auto n : t[c])
        {
            if (controla[n]) continue;
            return n;
        }

    return -1;
}
