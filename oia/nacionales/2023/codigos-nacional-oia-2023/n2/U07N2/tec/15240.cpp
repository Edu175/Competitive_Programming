#include <bits/stdc++.h>
using namespace std;
vector<vector<int>>grafo;
vector<bool>visits;
void tablero(int N, vector<int> &A, vector<int> &B) {
    // AQUI SE DEBE IMPLEMENTAR LA SOLUCION
    grafo.resize(N+1);
    visits.resize(N+1, false);
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
 int ress = 0;
int DFS(int nodo){
    visits[nodo] = true;

    //cout << "nodo dfs: " << nodo << endl;
    for(int i=0; i<grafo[nodo].size(); i++){
        int vecino = grafo[nodo][i];
     //   cout << "vecino: " << vecino << endl;
        if(controla.count(vecino) == 0) return vecino;
        else{
            if(visits[vecino] == false) ress = DFS(vecino);
        }
    }
    return -1;
}


int con_quien_comercio(vector<int> &controlados) {
    if(controlados.size() == grafo.size() - 1) return -1;
    controla.clear();
    visits.clear();
    visits.resize(grafo.size(), false);
    int res;
    for(auto &it: controlados) controla.insert(it);
    for(int i=0; i<(int)controlados.size(); i++){
        int nodo = controlados[i];


      //  cout << nodo << endl;
      //  cout << nodo << endl;
        for(long long j=0; j<(int)grafo[nodo].size(); j++){
            int vecino = grafo[nodo][j];
           // cout << vecino << " : " << controla.count(vecino) << endl;
            if(controla.count(vecino) == 0 && vecino != 0){
                return vecino;
            }
        }


       /* if(visits[nodo] == false) res = DFS(nodo);
        if(res != -1) return res;*/
    }
    return -1;
}
