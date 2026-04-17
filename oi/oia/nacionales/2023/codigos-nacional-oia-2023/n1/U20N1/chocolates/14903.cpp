#include <iostream>
#include <string>
#include <vector>

using namespace std;

int chocolates(int K, vector<int> &x) {
    int cajas=0, memo=0, dory=0;
    int tamanio;
    tamanio=x.size();
    //ORDENAR VECTOR DE MAYOR A MENOR:
    for(int g=0; g<tamanio; g++) {
        for (int r=0; r<tamanio; r++) {
            if (x[g]<x[r]) {
                dory=x[g];
                x[g]=x[r];
                x[r]=dory;
            }
        }
    }

    if (K==1) {
        for (int c=0; c<tamanio; c++) {
            cajas = cajas + x[c];
        }
    } else if (K==x.size()) {
        memo = x[0];
        for (int h=0; h<tamanio; h++){
           if (x[h] < memo) {
            memo = x[h];
           }
        }
        cajas = memo;
    } else {
        while (x.size()>=K) {
        x[0]=x[0]-1;
        x[1]=x[1]-1;
        x[x.size()-1]=x[x.size()-1]-1;
          for (int s=0; s<x.size(); s++) {
            if (x[s]==0){
                for (int f=s; f<x.size(); f++) {
                    x[f]=x[f+1];
                }
                x.pop_back();
            }
          }
        }
    }
    return cajas;
}
