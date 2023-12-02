
#include <string>
#include <vector>

using namespace std;

int chocolates(int K, vector<int> &x) {
    // AQUI SE DEBE IMPLEMENTAR LA SOLUCION
    int N,r=0,i=0;
    for(int i0=0;i0<123;i0++){
      if(x[i]>=1){
        i++;
        x[i0]--;
      }
      if(i==K){
        r=r+1;
        i=0;
      }
    }
    return r;
}