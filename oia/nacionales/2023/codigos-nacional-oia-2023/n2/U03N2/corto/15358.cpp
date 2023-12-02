#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void eliminarUnion(vector<vector<pair<int, int>>> &grafo, int i, int k){
    grafo[i].erase(grafo[i].begin() + k);
}

vector<int> entreCualYCual(vector<vector<pair<int, int>>> &grafo, int flecha){
    bool encontrado = false;
    vector<int> r;
    int i = 0, k;
    while(i < grafo.size() && !encontrado){
        k = 0;
        while(k < grafo[i].size() && !encontrado){
            encontrado = grafo[i][k].second == flecha;
            if (encontrado){
                    r.push_back(i);
                    r.push_back(grafo[i][k].first);
                    r.push_back(k);
            }
            k++;
        }
        i++;
    }
    return r;
}

void agregarNodo(vector<vector<pair<int, int>>> &grafo, int A, int B, int S, int N, int X){
    grafo[A].push_back(make_pair(N+1, S+1));
    grafo[N+1].push_back(make_pair(B, X));
}

void agregarNodo(vector<vector<pair<int, int>>> &grafo, int A, int B, int S, int N){
    grafo[A].push_back(make_pair(N+1, S+1));
    grafo[N+1].push_back(make_pair(B, S+2));
}

void adyacencias(vector<vector<pair<int, int>>> grafo, vector<int> &salida, vector<int> recorridos, int nodo){
    for(pair<int, int> par : grafo[nodo]){
            if(find(recorridos.begin(), recorridos.end(), par.first) == recorridos.end() && find(salida.begin(), salida.end(), par.first) == salida.end())
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
    vector<int> AB;
    grafo[1].push_back(make_pair(2, 1));
    for(int i = 0; i < t.size(); i++){
            numFlecha = e[i];
            AB = entreCualYCual(grafo, numFlecha);
            if(t[i] == 1){
                // Serie
                eliminarUnion(grafo, AB[0], AB[2]);
                agregarNodo(grafo, AB[0], AB[1], s, i+2, numFlecha);
                s++;
            }
            else{
                // Paralelo
                agregarNodo(grafo, AB[0], AB[1], s, i+2);
                s+= 2;
            }
    }
    // BFS
    int inicio = 1, fin = 2, posActual, mayorDistancia = s, cantCosasRecorridas = 1, tempSize;
    vector<int> aRecorrer;
    vector<int> recorridos;
    posActual = inicio;
    adyacencias(grafo, aRecorrer, recorridos, posActual);
    recorridos.push_back(posActual);
    posActual = aRecorrer[0];
    while(find(aRecorrer.begin(), aRecorrer.end(), fin) == aRecorrer.end()){
        tempSize = aRecorrer.size();
        for (int i = 0; i < tempSize; i++){
            adyacencias(grafo, aRecorrer, recorridos, posActual);
            aRecorrer.erase(aRecorrer.begin() + 0);
            recorridos.push_back(posActual);
            posActual = aRecorrer[0];
        }
        cantCosasRecorridas++;
    }
    return cantCosasRecorridas;
}
