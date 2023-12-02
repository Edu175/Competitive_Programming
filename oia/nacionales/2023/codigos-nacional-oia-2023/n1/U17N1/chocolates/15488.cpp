#include <bits/stdc++.h>

using namespace std;

int chocolates(int K, vector<int> &x) {
    // AQUI SE DEBE IMPLEMENTAR LA SOLUCION
     int aux=0, cont =0,suma=0;
    for (int i=0;i<x.size();i++)
    {

for(int j=i;j<i+K;j++)
{


           if(x[i]>=1&&x[i+j]>=1)
           {
            x[j]=x[j]-1;

         cont++;
           }
}



     }
     cont =cont/K;

     return cont;

}
