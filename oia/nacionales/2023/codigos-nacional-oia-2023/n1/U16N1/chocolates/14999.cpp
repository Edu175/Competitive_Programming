#include <string>
#include <vector>

using namespace std;

int chocolates(int K, vector<int> &x) {
    // AQUI SE DEBE IMPLEMENTAR LA SOLUCION
    int solucion;
    int seRepiten=0;
    int n = x.size(); //cuantos tipos
    vector <int> xNuevo(n); //modificable, los bombones
    for(int p=0; p < n; p++){
        xNuevo[p] = x[p];
    }

    vector <int> caja(K); //la caja a llenar
    int b=0;
    int v=0;
    int h=0;

    if(n == 1 && K != n){
        solucion = 0;
    }
    else{
while(xNuevo.size() > K){
    for(int i=0; i < n; i++){ //recorre xNuevo
       if(xNuevo[b] != caja[v]){
        v++;
       }
       if (v == n){
        caja[i] = xNuevo[b];
        b++;
        v = 0;
       }

    }

    for(int m=0; m < n; m++){     //sacar los usados en xNuevo
       if(caja[m] == xNuevo[h]){
        //borrar xNuevo[h]
        for(int u=h; u < xNuevo.size()-1; u++){
            xNuevo[u] = xNuevo[u+1];
        }
        xNuevo.pop_back();
       }
    }

    caja.clear();
    solucion++;
} }

    return solucion;
}
