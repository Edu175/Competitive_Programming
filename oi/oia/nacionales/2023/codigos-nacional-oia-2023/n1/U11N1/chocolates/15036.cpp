#include <string>
#include <vector>

using namespace std;

int chocolates(int K, vector<int> &x) {
  int tam = x.size(), cont = -1;
    if(tam == 1){
        return x[0];
    }
    else{
        for(int i = 0; i < tam; i++){
            while(x[i] > 0){
                for(int j = 1; j < K; j++){
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
