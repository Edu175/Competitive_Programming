#include <iostream>
#include <string>
#include <vector>

using namespace std;

void inicializar(int);
void cambiarTemperatura(int);

bool suena_alarma;
void alarma() {
    suena_alarma = true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, t; cin >> t >> n;
    inicializar(t);
    while(n --> 0) {
        int q; cin >> q;
        suena_alarma = false;
        cambiarTemperatura(q);
        if(suena_alarma) cout << "suena la alarma" << endl;
        else cout << "no suena la alarma" << endl;
    }
}
