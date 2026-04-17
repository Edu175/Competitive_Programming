#include <string>
#include <vector>

using namespace std;

vector<pair<int, int>> con;
vector<int> adj[20000001];
bool visited[20000001];

vector<int> pA;
int n = 0;
bool currTruth = false;

void dfs(int s)
{
    if(visited[s]) return;
    visited[s] = true;

    for(int p : pA) {
        if (s == p) {
                currTruth = true;
                break;
        }
    }

    for (auto a : adj[s]) {
        dfs(a);
    }
}

bool look(int s, int p) {
    for(auto n : pA) {
        if (p == n) return false;
    }

    for (auto u : con)
    {
        if(u.first != s)
            look(u.first, p);
    }
    return false;
}

void tablero(int N, vector<int> &A, vector<int> &B) {
    // AQUI SE DEBE IMPLEMENTAR LA SOLUCION
    for(int m = 0; m < A.size(); m++) {
            con.push_back({A[m], B[m]});
            adj[A[m]].push_back(B[m]);
            //pA.push_back(A[m]);
    }
    n = N;
}

int con_quien_comercio(vector<int> &controlados) {
    // AQUI SE DEBE IMPLEMENTAR LA SOLUCION
    return -1;
}
