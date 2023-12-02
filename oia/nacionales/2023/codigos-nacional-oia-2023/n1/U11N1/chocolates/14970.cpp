#include <string>
#include <vector>

using namespace std;

int chocolates(int K, vector<int> &x) {
    int tam = x.size(), cont = 0;
    if(tam == 1){
        return x[0];
    }
    else if(K == 2){
        for(int i = 0; i < tam; i++){
            for(int j = 1; j < K; j++){
                while(x[i+j] > 0){
                    x[i] -= 1;
                    x[i+j] -= 1;
                }
                cont += 1;
            }
        }
    }
    for(int i = 0; i < tam; i++){
        
    }
    return cont;
}