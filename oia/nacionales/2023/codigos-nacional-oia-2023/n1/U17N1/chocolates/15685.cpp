#include <bits/stdc++.h>

using namespace std;
int jj(int i,int k)
{
    for (int j=i;i<k;i++)
    {
        return j;
    }
}
int chocolates(int K, vector<int> &x) {
    // AQUI SE DEBE IMPLEMENTAR LA SOLUCION
     int aux=0, cont =0,suma=0,j;
    for (int i=0;i<x.size();i++)
    {
           if(x[i]>=1&&x[jj(i,K)+i]>=1)
           {
            x[jj(i,K)]=x[jj(i,K)]-1;
         cont++;
           }

     }

     return cont;

}
