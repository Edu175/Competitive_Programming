#include <vector>
#include <set>

using namespace std;

long long bombones(int K, vector<int> &x) {
    long long cantCajas = 0;
    int cantBomb = 0;
    set<int> eliminados;

    do
    {
        cantBomb = 0;
        for(int i=0; i<x.size(); i++)
        {
            if(x[i] > 0 && cantBomb < K)
            {
                x[i]--;
                cantBomb++;
                if(x[i] == 0 && eliminados.count(i) == 0)
                {
                    eliminados.insert(i);
                }
            }
            if(cantBomb == K) break;
            else if(eliminados.size() >= (x.size() - K)+1) break;
        }
        if(cantBomb == K) cantCajas++;
    }while (eliminados.size() < (x.size() - K)+1);
    
    return cantCajas;
}