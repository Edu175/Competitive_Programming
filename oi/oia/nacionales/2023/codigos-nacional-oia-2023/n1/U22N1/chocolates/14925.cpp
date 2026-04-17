#include <iostream>
#include <string>
#include <vector>

using namespace std;

int chocolates(int K, vector<int> &x) {
    int caja= 0;
    int contador = 0;
    int index = 0;
    while(x[index] >= 0){
        for(int i = 0; i < K; i++){
            if(x[i] != 0){
                caja += 1;
                x[index] -=1;
                contador += 1;
            }
        }
        index+=1;
    }

    return contador;
}
