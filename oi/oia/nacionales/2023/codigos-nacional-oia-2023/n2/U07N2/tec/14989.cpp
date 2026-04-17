#include <bits/stdc++.h>
using namespace std;
vector<vector<int>>grafo;
void tablero(int N, vector<int> &A, vector<int> &B) {
    // AQUI SE DEBE IMPLEMENTAR LA SOLUCION
    grafo.resize(N+1);
    for(int i=0; i<(int)A.size(); i++){
        grafo[A[i]].push_back(B[i]);
        grafo[B[i]].push_back(A[i]);
    }
}
set<int>controla;
int con_quien_comercio(vector<int> &controlados) {
    controla.clear();
    for(auto &it: controlados) controla.insert(it);
    for(int i=0; i<controlados.size(); i++){
        int nodo = controlados[i];
        for(int j=0; j<(int)grafo[nodo].size(); j++){
            int vecino = grafo[nodo][i];
            if(controla.count(vecino) == 0 && vecino != 0){
                return vecino;
            }
        }
    }
    return -1;
}
