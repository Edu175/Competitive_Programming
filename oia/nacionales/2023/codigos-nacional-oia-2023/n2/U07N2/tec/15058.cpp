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

    /*for(int i=1; i<=N; i++){
        cout << "nodo "<<i<<endl;
        for(int j=0; j<grafo[i].size(); j++){
            cout << grafo[i][j] << " ";
        }
        cout << endl;
    }*/
}
set<int>controla;
int con_quien_comercio(vector<int> &controlados) {
    controla.clear();
    for(auto &it: controlados) controla.insert(it);
    for(int i=0; i<controlados.size(); i++){
        int nodo = controlados[i];
      //  cout << nodo << endl;
        for(int j=0; j<(int)grafo[nodo].size(); j++){
            int vecino = grafo[nodo][j];
           // cout << vecino << " : " << controla.count(vecino) << endl;
            if(controla.count(vecino) == 0 && vecino != 0){
                return vecino;
            }
        }
    }
    return -1;
}
