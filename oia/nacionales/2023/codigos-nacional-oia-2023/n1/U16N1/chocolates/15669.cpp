#include <string>
#include <vector>
#include <iostream>

using namespace std;

int chocolates(int K, vector<int> &x) {

    int solucion =0;
    int lar; //tipos de bombones
    int tar; //si repiten
    int n = x.size(); //cuantos bombones
vector <int> xNuevo(n); //modificable, los bombones
    for(int p=0; p < n; p++){
        xNuevo[p] = x[p];
    }

    int r=0;

    for(int q=0; q < n; q++){
      if(xNuevo[q] == xNuevo[r]){
        tar++;
    }
    tar++;
    }
    lar = n - tar;

    if(lar == 1 && K != n){
        solucion = 0;
    }
    else if(lar == 1 && K == 1){
        solucion = n;
    }


 return solucion;
}

