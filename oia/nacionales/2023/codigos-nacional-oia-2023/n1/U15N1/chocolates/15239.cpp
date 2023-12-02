#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int chocolates(int K, vector<int> &x) {
    int cajas = 0, bombonesEnCaja = 0;
    while(true){
        bombonesEnCaja = 0;
        for(int i = x.size()-1; i >= 0; i--){
            if(x[i] != 0){
                x[i]--;
                bombonesEnCaja++;
                if(bombonesEnCaja == K){
                    cajas++;
                    break;
                }
            }
        }
        if(bombonesEnCaja < K) break;
    }
    return cajas;
}

