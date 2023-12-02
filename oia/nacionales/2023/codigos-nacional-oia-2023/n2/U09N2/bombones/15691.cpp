#include <iostream>
#include <string>
#include <vector>

using namespace std;

long long bombones(int K, vector<int> &x) {
    int num = x.size();
    vector<int> bombones = x;
    vector<int> bombones2;
    vector<int> bombonesUsados;
    long long cajas = 0;
    long long sumX = 0;
    long long p = 0;
    long long q = 0;

    for (int i = 0; i < num; i++){
        sumX += bombones[i];
    }
    
    //cout << "suma" << sumX << "\n";
    while(sumX >= p){
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
            cajas += 1;
        } else {
            if(bombones[q] != 0){
                bombonesUsados.push_back(q);
                bombones[q] += -1;
                p += 1;
                q += 1;
            } else {
                for (int i = 1; i < bombones.size(); i++){
                    bombones2.push_back(bombones[i]);
                }
                bombones = bombones2;
                bombones2.clear();
            }
        }
    }

    return cajas;
}