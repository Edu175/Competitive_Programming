#include <iostream>
#include <string>
#include <vector>

using namespace std;

void celdas(vector <string> &c, vector <int> &celdasTotal, vector <int> &celdasMismaHoja);

int main() {
    /*ios::sync_with_stdio(false);
    cin.tie(nullptr);*/
    int N;
    cin >> N;
    vector<string> c;
    c.resize(N);
    for (int i0 = 0; i0 < N; i0++) {
        cin >> c[i0];
    }
    vector<int> celdasTotal;
    celdasTotal.resize(0);
    vector<int> celdasMismaHoja;
    celdasMismaHoja.resize(0);
    celdas(c, celdasTotal, celdasMismaHoja);
    for (int i = 0; i < int(celdasTotal.size()); i++) {
        if (i > 0) cout << " ";
        cout << celdasTotal[i];
    }
    cout << "\n";
    for (int i = 0; i < int(celdasMismaHoja.size()); i++) {
        if (i > 0) cout << " ";
        cout << celdasMismaHoja[i];
    }
    cout << "\n";
    return 0;
}
