#include <iostream>
#include <string>
#include <vector>

using namespace std;

long long desalambrando(int N, vector<int> &a, vector<int> &b, vector<int> &costo);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    int M;
    cin >> M;
    vector<int> a;
    vector<int> b;
    vector<int> costo;
    a.resize(M);
    b.resize(M);
    costo.resize(M);
    for (int i = 0; i < M; i++) {
        cin >> a[i];
        cin >> b[i];
        cin >> costo[i];
    }
    long long returnedValue;
    returnedValue = desalambrando(N, a, b, costo);
    cout << returnedValue << "\n";
    return 0;
}
