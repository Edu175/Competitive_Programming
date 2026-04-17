#include <bits/stdc++.h>

using namespace std;

long long bombones(int K, vector<int> &x)
{
    if(x.size()==1)
    {
        return x[0];
    }
    if(K==1)
    {
        long long suma=0;
        for(int i=0; i<x.size(); i++)
        {
            suma+=x[i];
        }
        return suma;
    }
    bool pos = true;
    long long cantCaj = 0;
    sort(x.begin(),x.end());
    if(K==0)
    {
        return 0;
    }
    while(pos)
    {
        long long res = x[x.size()-K];
        for(int i=0; i<K; i++)
        {
            x[x.size()-i-1]-=res;
        }
        cantCaj+=res;
        sort(x.begin(),x.end());
        if(x[x.size()-K]==0)
        {
            pos=false;
        }
    }
    return cantCaj;

}
