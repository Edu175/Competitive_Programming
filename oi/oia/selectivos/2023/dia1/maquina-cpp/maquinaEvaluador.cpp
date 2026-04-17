#include <iostream>
#include <string>
#include <vector>

using namespace std;

int maquina(int T, vector<string> &lineas, vector<string> &orden);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    int T;
    cin >> T;
    vector<string> lineas;
    lineas.resize(N);
    for (int i0 = 0; i0 < N; i0++) {
        cin >> lineas[i0];
    }
    vector<string> orden;
    orden.resize(0);
    int returnedValue;
    returnedValue = maquina(T, lineas, orden);
    cout << returnedValue << "\n";
    for (int i = 0; i < int(orden.size()); i++) {
        if (i > 0) cout << " ";
        cout << orden[i];
    }
    cout << "\n";
    return 0;
}
