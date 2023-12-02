#include <string>
#include <vector>
#include <iostream>

using namespace std;

int chocolates(int K, vector<int> &x) {
    // AQUI SE DEBE IMPLEMENTAR LA SOLUCION
    int solucion;
    vector <int> noRepiten;
    int lar; //tipos de bombones
    int tar; //si repiten
    int n = x.size(); //cuantos bombones
    vector <int> xNuevo(n); //modificable, los bombones
    for(int p=0; p < n; p++){
        xNuevo[p] = x[p];
    }

    vector <int> caja(K); //la caja a llenar
    int b=0;
    int v=0;
    int h=0;
    int r=0;

    for(int q=0; q < n; q++){
      if(xNuevo[q] == xNuevo[r]){
        tar++;
    }
    tar++;
    }
    lar = n - tar;

    if(lar == 1 && K != n){
        solucion = 0;
    }
    else if(lar == 1 && K == 1){
        solucion = n;
    }
    else{
while(xNuevo.size() > K){
    for(int i=0; i < n; i++){ //recorre xNuevo
       if(xNuevo[b] != caja[v]){
        v++;
       }
       if (v >= n - 1){
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

/*int main(){
 int x;
 int cajaTam;


 cin >> cajaTam;
 cin >> x; //cuantos
 vector <int> bom(x);

 for(int i=0; i < x; i++){
    cin >> bom[i];
 }

 cout << chocolates(cajaTam, bom) << endl;


}*/
