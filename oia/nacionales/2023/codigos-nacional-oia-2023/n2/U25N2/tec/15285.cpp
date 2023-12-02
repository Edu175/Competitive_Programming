#include <string>
#include <vector>

using namespace std;

vector<pair<int, int>> con;
vector<int> pA;
int n = 0;

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
            pA.push_back(A[m]);
    }
    n = N;
}

int con_quien_comercio(vector<int> &controlados) {
    // AQUI SE DEBE IMPLEMENTAR LA SOLUCION
    int pos = -1;
    for(int i = 0; i < controlados.size(); i++)
    {
        if(look(0, i+1))
            return i+1;
    }
    return pos;
}
