#include <bits/stdc++.h>
using namespace std;

long long Piedras_Magicas(int N, int A, int B, int Q, vector<int> __a);

// GRADER
string filename = "sub0.1.in";
int T, N, A, B, Q, ANS, aux;
vector <int> __a;

int main() {
    ifstream infile(filename);
    infile >> T;
    for (int t = 1; t <= T; t++) {
        infile >> N >> A >> B >> Q;
        for (int i = 0; i < Q; i++) {
            infile >> aux;
            __a.push_back(aux);
        }
        infile >> ANS;

        cout << "Caso " << t << ": ";
        switch (ANS == Piedras_Magicas(N, A, B, Q, __a)) {
            case 1:
                cout << "Respuesta correcta :)\n";
                break;
            default:
                cout << "Respuesta erronea.\n";
                break;
        }

        __a.clear();
    }
    return 0;
}
