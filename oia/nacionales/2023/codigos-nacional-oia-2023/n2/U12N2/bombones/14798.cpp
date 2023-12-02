#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool revisar(int K, vector<int> x);

long long bombones(int K, vector<int> &x) {
    long long cantCajas = 0;
    int cantBomb = 0;
    bool sePuede = true;
    int actualPos = 0;
    
    while(sePuede)
    {  
        cantBomb = 0;
        sePuede = revisar(K, x);
        if(sePuede)
        {
            for(int i=actualPos; i<x.size(); i++)
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

bool revisar(int K, vector<int> x)
{
    int cantDisp = 0;
    for(auto i : x)
    {
        if(i > 0) cantDisp++;
    }
//    cout<<"c"<<cantDisp<<endl;
    return cantDisp >= K;
}