#include <iostream>
#include <string>
#include <vector>

using namespace std;

long long bombones(int K, vector<int> &x) {
    int num = x.size();
    //int sumK = 0;
    vector<int> bombonesUsados;
    long long sumX = 0;
    long long cajas = 0;
    for (int i = 0; i < num; i++){
        sumX += x[i];
    }
    
    long long p = 0;
    long long q = 0;
    while(sumX > p){
        if(bombonesUsados.size() == K){
            for (int n = 0; n < K; n++){
                for (int m = 0; m < K; m++){
                    if(bombonesUsados[n] == bombonesUsados[m] and n != m){
                        return cajas;
                    }
                }
            }
            bombonesUsados.clear();
            q = 0;
            cajas++;      
        } else {
            if(x[q] != 0){
                bombonesUsados.push_back(q);
                x[q] += -1;} 
            q++;
        }
        p++;
    }

}
