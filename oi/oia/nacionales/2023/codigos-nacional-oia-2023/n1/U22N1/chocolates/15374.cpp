#include <iostream>
#include <string>
#include <vector>

using namespace std;

int chocolates(int K, vector<int> &x) {
    vector<int>x1(x.size());
    for(int p = 0; p < x1.size(); p++){
        x1[p] = x[p];
    }
    int cajas;
    while(true){
        for(int i = 0; i < K; i++){
            if(x1[i] == 0){
                x1[i] = x1[x.size()-1];
                x1.pop_back();
            }else{
                x1[i] -= 1;
            }
        }
        cajas += 1;
        if(x.size() < K){
            break;
        }
    }
    return cajas;
}

