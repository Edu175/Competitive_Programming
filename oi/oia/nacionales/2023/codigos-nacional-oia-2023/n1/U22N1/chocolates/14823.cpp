#include <iostream>
#include <string>
#include <vector>

using namespace std;

int chocolates(int K, vector<int> &x) {
    vector<int> caja(K);
    int contador = 0;
    for(int i = 0; i < K; i++){
        caja[i] = x[i];
        x[i]-=1;
        if(x[i] == 0){
            break;
        }
        contador += 1;
    }
    return contador;
}
