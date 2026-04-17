#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void eliminarUnion(vector<vector<pair<int, int>>> &grafo, int flecha){
    bool eliminado = false;
    for(int i = 0; i < grafo.size(); i++){
            for (int k = 0; k < grafo[i].size(); k++){
                eliminado = grafo[i][k].second == flecha;
                if (eliminado) grafo[i].erase(grafo[i].begin() + k);
            }
    }
}

pair<int, int> entreCualYCual(vector<vector<pair<int, int>>> &grafo, int flecha){
    bool eliminado = false;
    pair<int, int> r;
    for(int i = 0; i < grafo.size(); i++){
            for (int k = 0; k < grafo[i].size(); k++){
                eliminado = grafo[i][k].second == flecha;
                if (eliminado){
                    r.first = i;
                    r.second = grafo[i][k].first;
                }
            }
    }
    return r;
}

void agregarNodo(vector<vector<pair<int, int>>> &grafo, int A, int B, int S, int N, int X){
    bool eliminado = false;
    grafo[A].push_back(make_pair(N+1, S+1));
    grafo[N+1].push_back(make_pair(B, X));
}

void agregarNodo(vector<vector<pair<int, int>>> &grafo, int A, int B, int S, int N){
    bool eliminado = false;
    grafo[A].push_back(make_pair(N+1, S+1));
    grafo[N+1].push_back(make_pair(B, S+2));
}

//void imprimirGrafo(vector<vector<pair<int, int>>> g){
//    for (int i = 0; i < g.size(); i++){
//        cout << "Uniones del nodo " << i << endl;
//        for (pair<int, int> par: g[i]){
//            cout << "Con nodo " << par.first << " y valor " << par.second;
//            cout << endl;
//        }
//    }
//    cout << endl;
//}

void adyacencias(vector<vector<pair<int, int>>> grafo, vector<int> &salida, vector<int> recorridos, int nodo){
    for(pair<int, int> par : grafo[nodo]){
            if(find(recorridos.begin(), recorridos.end(), par.first) != recorridos.end())
                salida.push_back(par.first);
    }
}

int corto(vector<int> &t, vector<int> &e) {
    if (t.size() == 1){
        if(t[0] == 1)
            return 2;
        return 1;
    }
    vector<vector<pair<int, int>>> grafo((int)t.size() + 3);
    int numFlecha, s = 1;
    pair<int, int> AB;
    grafo[1].push_back(make_pair(2, 1));
    for(int i = 0; i < t.size(); i++){
            numFlecha = e[i];
            AB = entreCualYCual(grafo, numFlecha);
            if(t[i] == 1){
                // Serie
                eliminarUnion(grafo, numFlecha);
                agregarNodo(grafo, AB.first, AB.second, s, i+2, numFlecha);
                s++;
            }
            else{
                // Paralelo
                agregarNodo(grafo, AB.first, AB.second, s, i+2);
                s+= 2;
            }
    }
    // BFS
//    int inicio = 1, fin = 2, posActual, mayorDistancia = s;
//    vector<int> aRecorrer;
//    vector<int> recorridos;
//    posActual = inicio;
//    adyacencias(grafo, aRecorrer, recorridos, posActual);
//    recorridos.push_back(posActual);
//    while(posActual != fin){
//        adyacencias(grafo, aRecorrer, recorridos, posActual);
//    }
//    imprimirGrafo(grafo);
    return 0;
}
