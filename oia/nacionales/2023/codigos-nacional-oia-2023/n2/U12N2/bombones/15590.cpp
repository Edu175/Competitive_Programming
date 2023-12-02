#include <vector>
using namespace std;
long long bombones(int K, vector<int> &x) {
    long long cantCajas = 0;
    bool sePuede = true; 
    do
    {  
        long long cantBomb = 0;
        long long cantDisp = 0;
        for(auto i : x)
        {
            if(i > 0) cantDisp++;
        }
        sePuede = cantDisp >= K;
        if(sePuede)
        {
            for(int i=0; i<x.size()-1; i++)
            {
                if(x[i]>0)
                {
                    x[i]--;
                    cantBomb++;
                }
                if(cantBomb == K) break;
            }
        }
        else break;
        if(cantBomb == K) cantCajas++;
    }while(sePuede);
    return cantCajas;
}

