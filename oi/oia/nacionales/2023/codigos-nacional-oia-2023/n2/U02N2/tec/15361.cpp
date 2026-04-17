#include <string>
#include <vector>

using namespace std;

void tablero(int N, vector<int> &A, vector<int> &B) {
    A=A;
}

int con_quien_comercio(vector<int> &controlados,vector<int> &A,vector<int> &B) {
    for(int i=0;i<controlados.size();i++){
        for(int j=0;j<A.size();j++){
            if(controlados[i]==A[j]){
                return B[j];
            }
        }
    }
}
