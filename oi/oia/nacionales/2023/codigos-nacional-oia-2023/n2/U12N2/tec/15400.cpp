#include <string>
#include <vector>

using namespace std;

int cantPaises;
vector<int> paA; 
vector<int> paB;


void tablero(int N, vector<int> &A, vector<int> &B) {
    cantPaises = N;
    paA = A;
    paB = B;
}

int con_quien_comercio(vector<int> &controlados) {
    int retornar = 0;
    for(int i=0; i<paA.size(); i++)
    {
        if(paA[i] == controlados[i] or paB[i] == controlados[i]) retornar++;
        else retornar = -1;
    }
    return retornar;
}
