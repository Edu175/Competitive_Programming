#include <iostream>
#include <string>
#include <vector>

using namespace std;

int vial(int K, int C, string &tipo, vector<int> &cuantos, vector<int> &pos, string &queHay);

int main() {
   // ios::sync_with_stdio(false);
   // cin.tie(nullptr);
    int K;
    cin >> K;
    int C;
    cin >> C;
    int T;
    cin >> T;
    int N;
    cin >> N;
    string tipo;
    vector<int> cuantos;
    tipo.resize(T);
    cuantos.resize(T);
    for (int i = 0; i < T; i++) {
        string elem;
        cin >> elem;
        tipo[i] = elem[0];
        cin >> cuantos[i];
    }
    vector<int> pos;
    string queHay;
    pos.resize(2*N);
    queHay.resize(2*N);
    for (int i = 0; i < 2*N; i++) {
        cin >> pos[i];
        string elem;
        cin >> elem;
        queHay[i] = elem[0];
    }
    int returnedValue;
    returnedValue = vial(K, C, tipo, cuantos, pos, queHay);
    cout << returnedValue << "\n";
    return 0;
}
