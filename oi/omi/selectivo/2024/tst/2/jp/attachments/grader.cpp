#include <bits/stdc++.h>

using namespace std;

int valor(int id);

int Reto_Sebas(int N);

// GRADER
string filename = "sub0.1.in";
int N, AR[100005], call;

int valor(int id) {
    if (id < 0 || id >= N) return -1;
    call++;
    return AR[id];
}

int main() {
    ifstream infile(filename);
    infile >> N;
    for (int i = 0; i < N; i++) infile >> AR[i];

    int x = Reto_Sebas(N), caso = 1;
    if (x >= N) caso = 3;
    else if (AR[x] != AR[(x + N/2)%N]) caso = 0;
    else if (call > 60) caso = 2;

    switch (caso) {
        case 0:
            cout << "Respuesta erronea.\n";
            break;
        case 1:
            cout << "Respuesta correcta :)\n";
            break;
        case 2:
            cout << "Numero de preguntas excedido.\n";
            break;
        case 3:
            cout << "Respuesta invalida.\n";
            break;
    }
    return 0;
}
