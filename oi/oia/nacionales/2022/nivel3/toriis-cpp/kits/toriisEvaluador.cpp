#include <iostream>
#include <string>
#include <vector>

using namespace std;

int toriis(int N, vector<int> &inicio, vector<int> &fin, vector<long long> &cantidad);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    int M;
    cin >> M;
    vector<int> inicio;
    vector<int> fin;
    vector<long long> cantidad;
    inicio.resize(M);
    fin.resize(M);
    cantidad.resize(M);
    for (int i = 0; i < M; i++) {
        cin >> inicio[i];
        cin >> fin[i];
        cin >> cantidad[i];
    }
    int returnedValue;
    returnedValue = toriis(N, inicio, fin, cantidad);
    cout << returnedValue << "\n";
    return 0;
}
