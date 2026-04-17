#include <iostream>
#include <string>
#include <vector>

using namespace std;

int editora(vector<int> &tinta, vector<long long> &articulos, string &ordenamiento);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<int> tinta;
    tinta.resize(10);
    for (int i0 = 0; i0 < 10; i0++) {
        cin >> tinta[i0];
    }
    int N;
    cin >> N;
    vector<long long> articulos;
    articulos.resize(N);
    for (int i0 = 0; i0 < N; i0++) {
        cin >> articulos[i0];
    }
    string ordenamiento;
    ordenamiento.resize(0);
    int returnedValue;
    returnedValue = editora(tinta, articulos, ordenamiento);
    cout << returnedValue << "\n";
    cout << ordenamiento << "\n";
    return 0;
}
