#include <vector>

using namespace std;

bool revisar(int K, vector<int> x)
{
    int cantDisp = 0;
    int cantCero = 0;
    for(auto i : x)
    {
        if(i > 0) cantDisp++;
        else cantCero++;

        if(cantCero > x.size()-K) break;
        
    }
    return cantDisp >= K;
}

long long bombones(int K, vector<int> &x) {
    long long cantCajas = 0;
    int cantBomb = 0;
    bool sePuede = true;
    
    while(sePuede)
    {  
        cantBomb = 0;
        sePuede = revisar(K, x);
        if(sePuede)
        {
            for(int i=0; i<x.size(); i++)
            {
                if(x[i]> 0 && cantBomb < K)
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

