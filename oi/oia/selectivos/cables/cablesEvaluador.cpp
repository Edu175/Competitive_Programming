#include <iostream>
#include <string>
#include <vector>

using namespace std;

int cables(vector<int> &P, vector<int> &L, long long M, vector<int> &elegidos);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    long long M;
    cin >> M;
    vector<int> P;
    vector<int> L;
    P.resize(N);
    L.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> P[i];
        cin >> L[i];
    }
    vector<int> elegidos;
    elegidos.resize(0);
    int returnedValue;
    returnedValue = cables(P,L,M,elegidos);
    cout << returnedValue << "\n";
    for (int i = 0; i < int(elegidos.size()); i++) {
        if (i > 0) cout << " ";
        cout << elegidos[i];
    }
    cout << "\n";
    return 0;
}
