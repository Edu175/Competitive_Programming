#include <iostream>
#include <string>
#include <vector>

using namespace std;

int chocolates(int K, vector<int> &x) {
    vector<int> caja(K);
    int contador = 0;
    int index = 0;
    for(int i = 0; i < x.size(); i++){
        if(x[i] > 0){
            for(int j = 0; j < x.size(); j++){
                x[j]-=1;
            }
            contador+=1;
        }
    }

    return contador;
}
