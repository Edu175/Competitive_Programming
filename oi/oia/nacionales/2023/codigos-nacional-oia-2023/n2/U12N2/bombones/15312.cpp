#include <vector>

using namespace std;

long long bombones(int K, vector<int> &x) {
    int cantCajas = 0;
    int cantBomb;
    bool sePuede;
    int xsize = x.size();
    
    do
    {  
        cantBomb = 0;
        int cantDisp = 0;

        for(auto i : x)
        {
            if(i > 0) cantDisp++; 
        }
        sePuede = cantDisp >= K;
        if(sePuede)
        {
            for(int i=0; i<xsize; i++)
            {
                if(x[i]>0 && cantBomb < K)
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

