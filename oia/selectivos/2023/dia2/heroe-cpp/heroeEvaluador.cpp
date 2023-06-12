#include <iostream>
#include <string>
#include <vector>

using namespace std;

long long heroe(vector<int> &a, vector<int> &b, vector<int> &t, vector<int> &e, vector<int> &secuencia);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    int M;
    cin >> M;
    vector<int> e;
    e.resize(N);
    for (int i0 = 0; i0 < N; i0++) {
        cin >> e[i0];
    }
    vector<int> a;
    vector<int> b;
    vector<int> t;
    a.resize(M);
    b.resize(M);
    t.resize(M);
    for (int i = 0; i < M; i++) {
        cin >> a[i];
        cin >> b[i];
        cin >> t[i];
    }
    vector<int> secuencia;
    secuencia.resize(0);
    long long returnedValue;
    returnedValue = heroe(a,b,t,e,secuencia);
    cout << returnedValue << "\n";
    for (int i = 0; i < int(secuencia.size()); i++) {
        if (i > 0) cout << " ";
        cout << secuencia[i];
    }
    cout << "\n";
    return 0;
}
