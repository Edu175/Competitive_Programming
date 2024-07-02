#include <bits/stdc++.h>

using namespace std;

int Flamante_Koala(int K, int N, vector<int> r1, vector<int> c1, vector<int> r2, vector<int> c2);

// GRADER
string filename = "sub0.1.in";
int K, N, T, aux, ANS;
vector <int> R1, C1, R2, C2;

int main() {
    ifstream infile(filename);
    infile >> T;
    for (int t = 1; t <= T; t++) {
        infile >> K >> N;
        for (int i = 0; i < N; i++) {
            infile >> aux;
            R1.push_back(aux);
        }
        for (int i = 0; i < N; i++) {
            infile >> aux;
            C1.push_back(aux);
        }
        for (int i = 0; i < N; i++) {
            infile >> aux;
            R2.push_back(aux);
        }
        for (int i = 0; i < N; i++) {
            infile >> aux;
            C2.push_back(aux);
        }

        infile >> ANS;

        cout << "Caso " << t << ": ";
        switch (ANS == Flamante_Koala(K, N, R1, C1, R2, C2)) {
            case 1:
                cout << "Respuesta correcta :)\n";
                break;
            default:
                cout << "Respuesta erronea.\n";
                break;
        }

        R1.clear();
        C1.clear();
        R2.clear();
        C2.clear();
    }
    return 0;
}
