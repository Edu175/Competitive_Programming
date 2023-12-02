#include <iostream>
#include <vector>

using namespace std;

void tablero(int N, vector<int> &A, vector<int> &B);
int con_quien_comercio(vector<int> &controlados);

int main() {
    int N,M;
    cin >> N >> M;
    vector<int> A(M),B(M);
    for (int i = 0; i < M; i++) {
        cin >> A[i];
        cin >> B[i];
    }
    tablero(N, A, B);
    int P;
    cin >> P;
    for (int i = 0; i < P; i++) {
        int C_i;
        cin >> C_i;
        vector<int> controlados(C_i);
        for (int j = 0; j < C_i; j++)
            cin >> controlados[j];
        cout << con_quien_comercio(controlados) << endl;
    }
    return 0;
}
