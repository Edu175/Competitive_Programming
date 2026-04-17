#include<bits/stdc++.h>
using namespace std;

long long bombones(int K, vector<int> &x) {
    long long c=0, x2=0;
    bool b=false;
    sort(x.rbegin() ,x.rend());
    if(K==1)
        for(int i=0; i<x.size();i++)
    {
        c=c+x[i];
    }
    else if(x.size()==1)
    c=x[0]/K;
    else{
    while(b==false)
    {
        int aux=0;
        for(long long j=0; j<x.size()-x2;j++)
        {
            if(x[j]>=1)
            {
                x[j]--;
                aux++;
            }
            else if(x[j]==0)
            {
                sort(x.rbegin() ,x.rend());
                x2++;
            }
            if(aux==K)
            {
                c++;
                break;
            }

        }
            if(aux<K)
                b=true;
    }
    }
    return c;
}
