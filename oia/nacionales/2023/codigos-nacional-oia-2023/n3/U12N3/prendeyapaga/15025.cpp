#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const ll MAXN = 200;

#define pb(v) push_back(v)

bool state[MAXN];
bool visitado[MAXN];

vector <ll> grafo[MAXN];

bool dfs (ll i) {

    visitado[i] = true;

    bool possible;

    if (state[i] == 0) {

        possible = false;

    } else {

        possible = true;

    }

    for (ll v : grafo[i]) {

        if (!visitado[v]) {

            possible = possible && dfs(v);

        }

    }

    return possible;

}

void resetvisitado () {

    for (int i = 0; i < MAXN; i++) {

        visitado[i] = false;

    }

}

vector<int> hoteles(vector<int>& padre, vector<int>& tipo, vector<int>& nodo) {

    vector <int> newpadre;

    newpadre.pb(0);

    for (int i = 0; i < padre.size(); i++) {

        newpadre.pb(padre[i]);

    }

    for (int i = 0; i < newpadre.size(); i++) {

        if (newpadre[i] != i) {

            grafo[newpadre[i]].pb(i);

        }

    }

    for (int i = 0; i < MAXN; i++) {

        state[i] = true;

    }

    ll q = tipo.size();

    vector <int> results;

    for (int i = 0; i < q; i++) {

        resetvisitado();

        ll query = nodo[i];

        if (tipo[i] == 1) {

            if (state[query] == 1) {

                results.pb(0);

            } else {

                state[query] = 1;
                results.pb(1);

            }

        } else {

            if (state[query] == 0) {

                results.pb(0);

            } else {

                bool possible = true;

                ll current = query;

                while (newpadre[current] != current) {

                    ll padreaux = newpadre[current];

                    if (state[padreaux] == 0) {

                        possible = false;
                        break;

                    } else {

                        current = newpadre[current];

                    }

                }

                possible = possible && dfs(query);

                if (possible) {

                    results.pb(1);
                    state[query] = 0;

                } else {

                    results.pb(0);

                }

            }

        }

    }

    return results;

}
