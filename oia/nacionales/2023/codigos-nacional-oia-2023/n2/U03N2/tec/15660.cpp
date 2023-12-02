#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> grafo;

void tablero(int N, vector<int> &A, vector<int> &B) {
    grafo.resize(N + 1);
    for(int i = 0; i < A.size(); i++){
        grafo[A[i]].push_back(B[i]);
        grafo[B[i]].push_back(A[i]);
    }
}

int paisEncontrado(int inicio, int fin){
    int posActual, mayorDistancia = s, tempSize;
    vector<int> aRecorrer;
    vector<int> recorridos;
    posActual = inicio;
    adyacencias(grafo, aRecorrer, recorridos, posActual);
    recorridos.push_back(posActual);
    posActual = aRecorrer[0];
    while(find(aRecorrer.begin(), aRecorrer.end(), fin) == aRecorrer.end() && aRecorrer.size() >= 1){
        tempSize = aRecorrer.size();
        for (int i = 0; i < tempSize; i++){
            adyacencias(grafo, aRecorrer, recorridos, posActual);
            aRecorrer.erase(aRecorrer.begin() + 0);
            recorridos.push_back(posActual);
            posActual = aRecorrer[0];
            if (posActual)
        }
    }
    return -1;
}

int con_quien_comercio(vector<int> &controlados) {
    // Buscar una union desde grafo 1

    return -1;
}
