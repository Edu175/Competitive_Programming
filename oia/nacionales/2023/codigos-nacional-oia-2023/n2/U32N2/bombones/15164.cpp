#include <bits/stdc++.h>

using namespace std;

long long bombones(int K, vector<int> &x)
{
    bool pos = true;
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
            if(x[x.size()-i-1]>0)
            {
                x[x.size()-i-1]--;
            }
            else
            {
                pos = false;
            }
        }
        sort(x.begin(),x.end());
        cantCaj++;

    }
    return cantCaj-1;

}

