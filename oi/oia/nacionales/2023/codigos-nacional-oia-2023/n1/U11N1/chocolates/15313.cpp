#include <string>
#include <vector>

using namespace std;

int chocolates(int K, vector<int> &x) {
    int tam = x.size(), cont = -1, j = 0, sum = 0;
    int largo = 0;
    for(int i=0;i<tam;i++){
        if(x[i] == 1){
            largo += 1;
        }
    }
    if(largo == tam){
        cont = K/tam;
        cont -= 1;
    }
    if(tam == 1){
        return x[0];
    }
    else if(K == 1){
        for(int y=0; y < tam; y++){
            sum += x[y];
        }
        return sum;
    }
    else if(K == 2){
        for(int i = 0; i < tam; i++){
            while((x[i] > 0)&&(x[i+1] > 0)){
                x[i] -= 1;
                x[i+1] -= 1;
                cont += 1;
            }
        }
        cont += 1;
    }
    else{
        for(int i = 0; i < tam; i++){
            while(x[i] > 0){
                x[i] -= 1;
                for(int y=0;y<K;y++){
                    if(x[i+y] > 0){
                        x[i+y] -= 1;
                    }
                }
                cont += 1;
                j++;
            }
            j = 0;
        }
    }
    return cont;
}
