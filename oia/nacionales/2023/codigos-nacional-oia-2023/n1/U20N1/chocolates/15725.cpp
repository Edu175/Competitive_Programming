#include <iostream>
#include <string>
#include <vector>

using namespace std;

int chocolates(int K, vector<int> &x) {
    int cajas=0, memo=0, dory=0;
    int tamanio=x.size();

    //ORDENAR VECTOR DE MAYOR A MENOR:
    for(int g=0; g<tamanio; g++) {
        for (int r=g+1; r<tamanio; r++) {
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

    } else if (K==2){
        while (x.size()>=K) {
            x[x.size()-1]--;
            x[x.size()-1]--;
            for (int s=0; s<x.size(); s++) {
                if (x[s]==0){
                    for (int f=s; f<x.size(); f++) {
                        x[f]=x[f+1];
                    }
                x.pop_back();
                }
                cajas++;
            }
        }

    }else{
       do {
        for (int q=0; q<K; q++) {
            x[q]-1;
        }
        //x[x.size()-1]=x[x.size()-1]-1;
        for (int s=0; s<x.size(); s++) {
            if (x[s]==0){
                for (int f=s; f<x.size(); f++) {
                    x[f]=x[f+1];
                }
                x.pop_back();
            }
         }
         cajas=cajas+1;

        } while (x.size()>=K);

    }
return cajas;
}
