#include <iostream>
#include <string>
#include <vector>

using namespace std;

long long escribiendo(long long C, vector<long long> &numeros);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long C;
    cin >> C;
    int N;
    cin >> N;
    vector<long long> numeros;
    numeros.resize(N);
    for (int i0 = 0; i0 < N; i0++) {
        cin >> numeros[i0];
    }
    long long returnedValue;
    returnedValue = escribiendo(C, numeros);
    cout << returnedValue << "\n";
    return 0;
}
