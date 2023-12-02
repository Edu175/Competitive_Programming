#include <string>
#include <vector>

using namespace std;

int chocolates(int K, vector<int> &x) {
    int tam = x.size(), cont = 0;
    for(int i = 0; i < tam; i++){
        while((x[i] > 0)&&(x[i+1] > 0)&&(x[i+2] > 0)){
            x[i] -= 1;
            x[i+1] -= 1;
            x[i+2] -= 1;
            cont += 1;
        }
    }
    return cont;
}