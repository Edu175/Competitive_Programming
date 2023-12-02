#include <bits/stdc++.h>

using namespace std;

using ll = long long;

#define pb(v) push_back(v)

int autocompletando(int K, vector<string> &r1, vector<string> &r2, vector<string> &r3, string &texto) {

    ll k = K;

    vector <string> palabras;

    string aux;

    for (int i = 0; i < texto.size(); i++) {

        if (texto[i] != ' ') {

            aux.pb(texto[i]);

        } else {

            palabras.pb(aux);
            aux = "";

        }

    }

    palabras.pb(aux);

    ll contador = palabras.size();

    ll n = palabras.size();

    string first = r1[0];
    string second = r2[0];
    string third = r3[0];

    for (int i = 0; i < n - 2; i++) {

        if (palabras[i] == first && palabras[i + 1] == second) {

            if (palabras[i + 2] == third) {

                contador--;

            }

        }

    }

    if (contador <= k) {

        return 1;

    } else {

        return 0;

    }

}
