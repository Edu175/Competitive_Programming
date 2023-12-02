#include <iostream>
#include <string>
#include <vector>

using namespace std;

int chocolates(int K, vector<int> &x) {
    int cajas;
    while(true){
        for(int i = 0; i < K; i++){
            if(x[i] == 0){
                x[i] = x[x.size()-1];
                x.pop_back();
            }else{
                x[i] -= 1;
            }
        }
        cajas += 1;
        if(x.size() < K){
            break;
        }
    }
    return cajas;
}

