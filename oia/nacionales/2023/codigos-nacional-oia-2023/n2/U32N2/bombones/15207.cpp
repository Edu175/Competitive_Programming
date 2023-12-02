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
    int minPos=x.size()-K;
    vector<int>posis(K);
    for(int i=0; i<posis.size(); i++)
    {
        posis[i]=x.size()-i-1;
    }
    long long cantCaj = 0;
    sort(x.begin(),x.end());
    if(K==0)
    {
        return 0;
    }
    while(pos)
    {
        for(int i=0; i<K; i++)
        {
            if(x[posis[i]]>0)
            {
                x[posis[i]]--;
            }
            else
            {
                if(minPos-1>0)
                {
                    minPos--;
                    posis[i]=minPos;
                }
                else
                {
                    pos = false;
                }
            }
        }
        cantCaj++;

    }
    return cantCaj;

}
