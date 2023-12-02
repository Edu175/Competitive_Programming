#include <bits/stdc++.h>

using namespace std;

int chocolates(int K, vector<int> &x)
{// AQUI SE DEBE IMPLEMENTAR LA SOLUCION

int Return=0, z=0, brk=0;
vector<int> caja(K+1);
vector<int> org(x.size());

for (int i=0; i<x.size();i++)
{
    org[i] = x[i];
}

sort(org.begin(), org.end());

if (x.size() == 1)
    {
      Return = x[0]; return Return;
    }

for (int i=0; i<x.size(); i++)
    {
        z=z+x[i];
    }

if (K==1) {Return = z; return Return;}

for (int i0=0;i0<z;i0++)
{   for (int i=0; i<K; i++)
    {
        if (org[org.size()-1]==0){  org.resize(x.size()-1); }

        caja[i] = i+1;
        org.end() -= 1;
        if (caja[i]=0){brk = 1; break;} else {Return++;}
    }
    if (brk=1) {break;}









    }




 return Return;

}
