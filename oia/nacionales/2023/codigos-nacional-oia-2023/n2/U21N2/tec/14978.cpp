#include <string>
#include <vector>

#define M_MAX 2000001

using namespace std;

vector<int> t[M_MAX];
int n;

void tablero(int N, vector<int> &A, vector<int> &B) {
    n = N;

    int M = A.size();
    for (int i = 0; i < M; ++i)
    {
        t[A[i]].push_back(B[i]);
        t[B[i]].push_back(A[i]);
    }
}

int con_quien_comercio(vector<int> &controlados) {
    bool controla[n+1];
    for (int i = 1; i <= n; ++i)
        controla[i] = false; 

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
