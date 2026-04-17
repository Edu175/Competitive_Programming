#include <bits/stdc++.h>

using namespace std;

int chocolates(int K, vector<int> &x) {
    // AQUI SE DEBE IMPLEMENTAR LA SOLUCION
     int aux=0, cont =0,suma=0;
    for (int i=0;i<x.size();i++)
    {

           if(x[i]>=1)
           {


            x[i]=x[i]-1;
            x[i+1]--;
            cont++;
           }


     }

     return cont;

}
