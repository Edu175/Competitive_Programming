#include <bits/stdc++.h>

#define debug(x) cout << #x << ": " << x << endl;

using namespace std;

void armarVecHijos(int r, vector<int> &padre, vector<vector<int>> &hijos, vector<bool> &isLeaf) {
    if(isLeaf[r]) return;

    bool rTieneHijos = false;
    for(int i = 0; i < padre.size(); i++) {
        if(padre[i] != r) continue;

        rTieneHijos = true;

        hijos[r].push_back(i+1);

        if(hijos[i+1].size() > 0) {
            for(int x : hijos[i+1]) hijos[r].push_back(x);
            break;
        }

        armarVecHijos(i+1, padre, hijos, isLeaf);
    }

    if(!rTieneHijos) isLeaf[r] = true;

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

bool dfsAscendente(int r, vector<int>& padre, vector<bool>& isRetrans, bool nodeShouldBeRentrans) {
    if(r == 0) return isRetrans[r] == nodeShouldBeRentrans;
    if(isRetrans[r] == nodeShouldBeRentrans) return dfsAscendente(padre[r-1], padre, isRetrans, nodeShouldBeRentrans);
    return false;
}

vector<int> hoteles(vector<int>& padre, vector<int>& tipo, vector<int>& nodo) {
    vector<int> Q = vector<int>(0, 0);
    vector<bool> isRetrans = vector<bool>(padre.size()+1, true);
    vector<vector<int>> hijos = vector<vector<int>>(padre.size() + 1, vector<int>(0, 0));
    vector<bool> isLeaf = vector<bool>(padre.size()+1, false);

    for(int i = 0; i < tipo.size(); i++) {
        if(tipo[i] == 0) {
            //change to wifi
            if(isRetrans[nodo[i]] == false) {Q.push_back(0); continue;} //if node is already in Wifi.

            bool sePuedeCambiarAsc = dfsAscendente(nodo[i], padre, isRetrans, true);

            if(!sePuedeCambiarAsc) {Q.push_back(0); continue;}

            armarVecHijos(nodo[i], padre, hijos, isLeaf);

            /*for(int x = 0; x < hijos.size(); x++) {
                for(int y = 0; y < hijos[x].size(); y++) {
                    debug(x);
                    debug(y);
                    debug(hijos[x][y]);
                }
            }*/

            bool sePuedeCambiarDes = dfsDescendente(nodo[i], hijos, isRetrans, true);

            if(!sePuedeCambiarDes) {Q.push_back(0); continue;}

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