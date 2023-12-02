#include <bits/stdc++.h>

#define debug(x) cout << #x << ": " << x << endl;

using namespace std;

void armarVecHijos(int r, vector<int> &padre, vector<vector<int>> &hijos) {
    for(int i = 0; i < padre.size(); i++) {
        if(padre[i] != r) continue;

        hijos[r].push_back(i+1);

        if(hijos[i+1].size() > 0) {
            for(int x : hijos[i+1]) hijos[r].push_back(x);
            break;
        }

        armarVecHijos(i+1, padre, hijos);
    }

    return;
}

bool dfsDescendente(int r, vector<vector<int>>& hijos, vector<bool> &isRetrans, bool nodeShouldBeRentrans) {
    if(isRetrans[r] == nodeShouldBeRentrans) {
        for(auto x : hijos[r]) {
            bool res = dfsDescendente(x, hijos, isRetrans, nodeShouldBeRentrans);
            if(res == false) return false;
        }
        return true;
    }
    return false;
}

void marcarCambioDesc(int r, vector<vector<int>> &hijos, vector<bool> &subtreeCambiado, bool newVal) {
    if(subtreeCambiado[r] == newVal) return;
    subtreeCambiado[r] = newVal;
    for(auto x : hijos[r]) {
        marcarCambioDesc(x, hijos, subtreeCambiado, newVal);
    }
}

bool dfsAscendente(int r, vector<int>& padre, vector<bool>& isRetrans, bool nodeShouldBeRentrans) {
    if(r == 0) return isRetrans[r] == nodeShouldBeRentrans;
    if(isRetrans[r] == nodeShouldBeRentrans) return dfsAscendente(padre[r-1], padre, isRetrans, nodeShouldBeRentrans);
    return false;
}

void marcarCambioAsc(int r, vector<int>& padre, vector<bool> &subtreeCambiado, bool newVal) {
    if(subtreeCambiado[r] == newVal) return;
    subtreeCambiado[r] = newVal;
    if(r == 0) return;
    marcarCambioAsc(padre[r-1], padre, subtreeCambiado, newVal);
}

vector<int> hoteles(vector<int>& padre, vector<int>& tipo, vector<int>& nodo) {
    vector<int> Q = vector<int>(0, 0);
    vector<bool> isRetrans = vector<bool>(padre.size()+1, true);
    vector<vector<int>> hijos = vector<vector<int>>(padre.size() + 1, vector<int>(0, 0));
    vector<bool> subtreeCambiado = vector<bool>(padre.size()+1, false);

    armarVecHijos(0, padre, hijos);

    for(int i = 0; i < tipo.size(); i++) {
        if(tipo[i] == 0) {
            //change to wifi
            if(isRetrans[nodo[i]] == false) {Q.push_back(0); continue;} //if node is already in Wifi.

            if(!subtreeCambiado[nodo[i]]) {

                marcarCambioAsc(nodo[i], padre, subtreeCambiado, true);
                marcarCambioDesc(nodo[i], hijos, subtreeCambiado, true);

                isRetrans[nodo[i]] = false;

                Q.push_back(1);
                continue;
            }

            bool sePuedeCambiarAsc = dfsAscendente(nodo[i], padre, isRetrans, true);

            if(!sePuedeCambiarAsc) {Q.push_back(0); continue;}

            /*for(int x = 0; x < hijos.size(); x++) {
                for(int y = 0; y < hijos[x].size(); y++) {
                    debug(x);
                    debug(y);
                    debug(hijos[x][y]);
                }
            }*/

            bool sePuedeCambiarDes = dfsDescendente(nodo[i], hijos, isRetrans, true);

            if(!sePuedeCambiarDes) {Q.push_back(0); continue;}

            marcarCambioAsc(nodo[i], padre, subtreeCambiado, false);
            marcarCambioDesc(nodo[i], hijos, subtreeCambiado, false);

            isRetrans[nodo[i]] = false;

            Q.push_back(1);
        } else {
            //change to retrans
            if(isRetrans[nodo[i]] == true) {Q.push_back(0); continue;}

            isRetrans[nodo[i]] = true;

            Q.push_back(1);
        }
    }
    return Q;
}

/*int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    vector<int> padre;
    padre.resize(N);
    for (int i0 = 0; i0 < N; i0++) {
        cin >> padre[i0];
    }
    int Q;
    cin >> Q;
    vector<int> tipo;
    vector<int> nodo;
    tipo.resize(Q);
    nodo.resize(Q);
    for (int i = 0; i < Q; i++) {
        cin >> tipo[i];
        cin >> nodo[i];
    }
    vector<int> returnedValue;
    returnedValue = hoteles(padre, tipo, nodo);
    for (int i = 0; i < int(returnedValue.size()); i++) {
        if (i > 0) cout << " ";
        cout << returnedValue[i];
    }
    cout << "\n";
    return 0;
}*/

//S1: 48, S2: 43, S4: 48, S5: 48