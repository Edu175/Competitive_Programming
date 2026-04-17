#include <iostream>
#include <string>
#include <vector>

using namespace std;

int chocolates(int K, vector<int> &x) {
    vector<int> caja(K);
    int contador = 0;
    int index = 0;
    while(x[index] != 0){
        for(int i = 0; i < K; i++){
            if(x[i] != 0){
                caja[i] += 1;
                x[i]-=1;
            }else{
                x[i] = x[x.size()-1];
                x.pop_back();
            }
        }
        contador += 1;
    }

    return contador;
}

