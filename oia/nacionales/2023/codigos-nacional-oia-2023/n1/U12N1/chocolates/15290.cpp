
#include <string>
#include <vector>

using namespace std;

int chocolates(int K, vector<int> &x) {
    // AQUI SE DEBE IMPLEMENTAR LA SOLUCION
    int N,d=0,r=0,i;
    for(i=0;i<1000;i++){
      if(x[i]>=1){
        d++;
        x[i]--;
      }
      if(d==K){
        r++;
        d=0;
      }
    }
    return x[0];
}