#include <vector>

using namespace std;

bool revisar(int K, vector<int> x)
{
    int cantDisp = 0;
    for(auto i : x)
    {
        if(i > 0) cantDisp++;
    }
    return cantDisp >= K;
}

long long bombones(int K, vector<int> &x) {
    long long cantCajas = 0;
    int cantBomb = 0;
    
    while(revisar(K, x))
    {  
        cantBomb = 0;
        if(revisar(K, x))
        {
            for(int i=0; i<x.size(); i++)
            {
                if(x[i]>0 && cantBomb < K)
                {
                    x[i]--;
                    cantBomb++;
                }
                if(cantBomb == K) break;
            }
        }
        if(cantBomb == K) cantCajas++;
    }

    return cantCajas;
}

