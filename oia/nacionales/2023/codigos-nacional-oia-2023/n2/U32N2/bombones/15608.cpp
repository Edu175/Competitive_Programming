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
        int res=x[x.size()-K];
        for(int i=0; i<K; i++)
        {
            if(x[x.size()-i-1]>0)
            {
                x[x.size()-i-1]-=res;
            }
            else
            {
                pos = false;
            }
        }
        sort(x.begin(),x.end());
        cantCaj+=res;

    }
    return cantCaj;

}

