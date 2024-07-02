#include <bits/stdc++.h>
using namespace std;

vector<int> El_Robot_Shor(int N, int Q, vector<int> p, vector<int> u, vector<int> v);

// GRADER
string filename = "sub0.1.in";
int N, Q, aux, ANS, T;
vector <int> p, u, v, userans;

int main() {
    ifstream infile(filename);
    infile >> T;
    for (int t = 1; t <= T; t++) {
        infile >> N;
        infile >> Q;
        for (int i = 0; i < N; i++) {
            infile >> aux;
            p.push_back(aux);
        }
        for (int i = 0; i < Q; i++) {
            infile >> aux;
            u.push_back(aux);
        }
        for (int i = 0; i < Q; i++) {
            infile >> aux;
            v.push_back(aux);
        }

        bool flag = true;
        userans = El_Robot_Shor(N, Q, p, u, v);

        if ((int)(userans.size()) == Q + 1) {
            for (int i = 0; i < Q + 1; i++) {
                infile >> ANS;
                if (ANS != userans[i]) flag = false;
            }
        }
        else flag = false;

        cout << "Caso " << t << ": ";
        switch (flag) {
            case 1:
                cout << "Respuesta correcta :)\n";
                break;
            default:
                cout << "Respuesta erronea.\n";
                break;
        }

        p.clear();
        u.clear();
        v.clear();
    }
    return 0;
}
