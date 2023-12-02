#include <string>
#include <vector>
#include <algorithm>

#define M_MAX 2000001

using namespace std;

vector<int> adj[M_MAX];
int n;

void tablero(int N, vector<int> &A, vector<int> &B) {
    n = N;

    int M = (int)A.size();
    for (int i = 0; i < M; ++i)
    {
        adj[A[i]].push_back(B[i]);
        adj[B[i]].push_back(A[i]);
    }
}

int con_quien_comercio(vector<int> &controlados) {
    if ((int)controlados.size() == n) return -1;
    vector<bool> controla(n+1);

    for (auto c : controlados)
    {
        controla[c] = true;
        for (auto p : adj[c])
        {
            if (controla[p]) continue;
            if (binary_search(controlados.begin(), controlados.end(), p))
            {
                controla[p] = true;
                continue;
            }

            return p;
        }
    }

    return -1;
}
