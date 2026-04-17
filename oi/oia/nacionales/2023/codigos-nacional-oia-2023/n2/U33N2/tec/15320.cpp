#include <string>
#include <vector>

using namespace std;

vector<vector<int>> tab;

void tablero(int N, vector<int> &A, vector<int> &B) {
    tab = vector<vector<int>>(N + 1, vector<int>(N + 1, 0));
    for(int i = 0; i < A.size(); i++){
        tab[A[i]][B[i]] = 1;
        tab[B[i]][A[i]] = 1;
    }
}

int con_quien_comercio(vector<int> &controlados) {
    for(int cont : controlados){
        for(int i = 1; i <= tab.size(); i++){
            if(tab[cont][i] == 1 && i != cont)
                return i;
        }
    }
    return -1;
}
