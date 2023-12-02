#include <bits/stdc++.h>

using namespace std;

int chocolates(int K, vector<int> &x)
{// AQUI SE DEBE IMPLEMENTAR LA SOLUCION

int Return=0, z=0, brk=0;
vector<int> caja(K+1);
vector<int> org(x.size());

int it=0, j=0;

for (int i=0; i<x.size(); i++)
    {
        z=z+x[i];
    }





Return = z/K;

 return Return;

}
