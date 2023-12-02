#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int chocolates(int K, vector<int> &x) {
    int cajas = 0,bombonesEnCaja;
    sort(x.begin(),x.end());
    while(true){
        bombonesEnCaja = 0;
        for(int i = 0; i < x.size(); i++){
            if(x[i] > 0){
                x[i] -= 1;
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


