#include <iostream>
#include <string>
#include <vector>

using namespace std;

long long bombones(int K, vector<int> &x) {
    int N = x.size();
    int sumK = 0;
    long long sumX = 0;
    long long cajas = 0;
    //int max = x[0];
    vector<int> indices;
    for (int index = 0; index < N; index++){

        sumX += x[index];
    }

    //cout << max << "\n";

    if(K == 1){
        cajas += sumX;
        return cajas;
    }
    
    int i = 0;
    int j = 0;
        while (i < sumX){
        if(sumK == K) {
            for (int b = 0; b < indices.size(); b++){
                for (int c = 0; c < indices.size(); c++){
                       if(indices[b] == indices[c] and b != c){
                           return cajas;
                       } else {
                            indices.clear();
                            j=0;
                            sumK=0;
                            cajas+=1;
                       }}}
            
        } else {
        if(x[j] == 0){} else {
            indices.push_back(j);
            x[j] -= 1;
            sumK+=1;
        }
            j+=1;
            i+=1;
        }
        
    }
    return cajas;
}
