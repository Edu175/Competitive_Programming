#include <bits/stdc++.h>

using namespace std;

int chocolates(int K, vector<int> &x)
{// AQUI SE DEBE IMPLEMENTAR LA SOLUCION

int Return=0, z=0, brk=0;
vector<int> caja(K+1);
vector<int> org(x.size());
int it=0, j=0;

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

if (K==1 || x.size() == K) {Return = z; return Return;}

it++;

for (int i=0; i<z;){

if (org[i] != 0)
{
caja[it]=it;
org[i] -=1;
j=0;
it++;
} else { j++; i++; }
if (caja[K] != 0) { Return=Return+1; it=0; j=0;} else { j++; }

if (j==2 || Return > z){break;}

}

 return Return;

}
