#include <iostream>
#include <string>
#include <vector>

using namespace std;

int tablero(string &pieza, string &salida, string &llegada, vector<string> &escaques);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string pieza;
    cin >> pieza;
    string salida;
    cin >> salida;
    string llegada;
    cin >> llegada;
    vector<string> escaques;
    escaques.resize(8);
    for (int i0 = 0; i0 < 8; i0++) {
        cin >> escaques[i0];
    }
    int returnedValue;
    returnedValue = tablero(pieza, salida, llegada, escaques);
    cout << returnedValue << "\n";
    return 0;
}
