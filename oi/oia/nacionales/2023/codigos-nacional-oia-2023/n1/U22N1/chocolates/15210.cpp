#include <iostream>
#include <string>
#include <vector>

using namespace std;

int chocolates(int K, vector<int> &x) {
    int contador = 0;
    int cant = x.size();
    vector<int> x1;
    while(cant >= K){
        for(int i = 0; i < K; i++){
            if(x[i] == 0){
                x[i] = x[cant-1];
                x.pop_back();
                cant-=1;
            }else{
                x[i]-=1;
            }
        }
        contador+=1;
    }

    return contador;
}
