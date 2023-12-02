#include <string>
#include <vector>

using namespace std;

int chocolates(int K, vector<int> &x) {
  int tam = x.size(), cont = -1, j = 0, sum = 0;
    if(tam == 1){
        return x[0];
    }
    else if(K == 1){
        for(int y=0; y < tam; y++){
            sum += x[y];
        }
        return sum;
    }
    else{
        for(int i = 0; i < tam; i++){
            while((x[i] > 0)&&(j < K)){
                x[i] -= 1;
                x[i+j] -= 1;
                cont += 1;
                j++;
            }
            j = 0;
        }
    }
    return cont;
}
