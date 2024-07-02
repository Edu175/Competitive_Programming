#include <bits/stdc++.h>

using namespace std;

int Doblemente_Aficionados(int N, vector<int> a);

// GRADER
string filename = "sub0.1.in";
int T, N, ANS;

int main() {
    ifstream infile(filename);
    infile >> T;
    for (int t = 1; t <= T; t++) {
        infile >> N;
        vector<int> AR(N);
        for (int i = 0; i < N; i++) infile >> AR[i];
        infile >> ANS;

        cout << "Caso " << t << ": ";
        switch (ANS == Doblemente_Aficionados(N, AR)) {
            case 0:
                cout << "Respuesta erronea.\n";
                break;
            case 1:
                cout << "Respuesta correcta :)\n";
                break;
        }
    }
    return 0;
}
