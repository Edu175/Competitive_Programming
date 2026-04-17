#include <vector>
#include<algorithm>
using namespace std;

long long bombones(int K, vector<int> &x) {
    long long cantCajas = 0;
    int cantBomb = 0;
    int cantDisp = 0;
    
    sort(x.begin(), x.end());
    reverse(x.begin(), x.end());

    do
    {  
        cantBomb = 0;
        
            for(int i=0; i<x.size(); i++)
            {
                if(x[i]> 0 && cantBomb < K)
                {
                    x[i]--;
                    cantBomb++;
                }
                if(cantBomb == K) break;
            }
        if(cantBomb == K) cantCajas++;

        cantDisp = 0;
        for(auto i : x)
        {
            if(i > 0) cantDisp++;        
        }
    }while(cantDisp >= K);

    return cantCajas;
}

