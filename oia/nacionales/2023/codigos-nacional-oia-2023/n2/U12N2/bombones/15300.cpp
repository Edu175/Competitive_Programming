#include <vector>

using namespace std;

long long bombones(int K, vector<int> &x) {
    int cantCajas = 0;
    int cantBomb = 0;
    bool sePuede = true;
    bool hayCero = true;
    
    do
    {  
        cantBomb = 0;
        int cantDisp = 0;

        if(hayCero)
        {
            for(auto i : x)
            {   
                if(i > 0) cantDisp++; 
            }
            sePuede = cantDisp >= K;
            hayCero = false;
        }
        if(sePuede)
        {
            for(int i=0; i<x.size(); i++)
            {
                if(x[i]>0 && cantBomb < K)
                {
                    x[i]--;
                    cantBomb++;
                }
                if(x[i] == 0) hayCero = true;
                if(cantBomb == K) break;
            }
        }
        else break;
        if(cantBomb == K) cantCajas++;
    }while(sePuede);

    return cantCajas;
}

