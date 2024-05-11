#include <iostream>
#include <string>
#include <vector>

using namespace std;

long long saltarines(int K, vector<int> &elegancias, vector<int> &ubicaciones);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    int K;
    cin >> K;
    vector<int> elegancias;
    elegancias.resize(N);
    for (int i0 = 0; i0 < N; i0++) {
        cin >> elegancias[i0];
    }
    int C;
    cin >> C;
    vector<int> ubicaciones;
    ubicaciones.resize(C);
    for (int i0 = 0; i0 < C; i0++) {
        cin >> ubicaciones[i0];
    }
    long long returnedValue;
    returnedValue = saltarines(K, elegancias, ubicaciones);
    cout << returnedValue << "\n";
    return 0;
}
