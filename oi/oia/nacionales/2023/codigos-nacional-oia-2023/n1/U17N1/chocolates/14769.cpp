#include <bits/stdc++.h>

using namespace std;

int chocolates(int K, vector<int> &x) {
    // AQUI SE DEBE IMPLEMENTAR LA SOLUCION
     int cont =0,suma=0;
    for (int i=0;i<x.size();i++)
    {
     if(K==1)
     {
          suma=suma+x[i];
     }
    }
    return suma;
}
