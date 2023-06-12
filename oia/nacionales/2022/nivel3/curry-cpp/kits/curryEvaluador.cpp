#include <iostream>
#include <string>
#include <vector>

using namespace std;

long long curry(vector<string> &palabras, vector<int> &significados);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    vector<string> palabras;
    vector<int> significados;
    palabras.resize(N);
    significados.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> palabras[i];
        cin >> significados[i];
    }
    long long returnedValue;
    returnedValue = curry(palabras, significados);
    cout << returnedValue << "\n";
    return 0;
}
