#include <iostream>
#include <string>
#include <vector>

using namespace std;

int chocolates(int K, vector<int> &x) {
    int cajas=0, memo=0, dory=0;

    //ORDENAR VECTOR DE MAYOR A MENOR:
    for(int g=0; g<x.size(); g++) {
        for (int r=0; r<x.size(); r++) {
            if (x[g]<x[r]) {
                dory=x[g];
                x[g]=x[h];
                x[h]=dory;
            }
        }
    }

    if (K==1) {
        for (int c=0; c<x.sixe(); c++) {
            cajas = cajas + x[c];
        }
    } else if (K==x.size()) {
        memo = x[0];
        for (h=0; h<x.size(); h++){
           if (x[h] < memo) {
            memo = x[h];
           }
        }
        cajas = memo;
    } else {
        while (x.size()>0) {

        }
    }
    return cajas;
}
