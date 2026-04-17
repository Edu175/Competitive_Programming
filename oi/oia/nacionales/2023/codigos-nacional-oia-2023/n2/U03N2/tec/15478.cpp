#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> mateo;
vector<int> externos;
int totalPaises;

void tablero(int N, vector<int> &A, vector<int> &B) {
    totalPaises = N;
    mateo = A;
    externos = B;
}

int con_quien_comercio(vector<int> &controlados) {
    int r = -1;
    for (int i = 0; i < controlados.size(); i++){
        if (find(externos.begin(), externos.end(), controlados[i]) == externos.end())
            return controlados[i];
    }
    return -1;
}
