#include <string>
#include <vector>
#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <algorithm>


using namespace std;

int calcularcajas(int K, vector<int> x) {
int cajas = 0;
int F = 0;

while (F <= x.size() - K) {

if (x[F] == 0) {F++;} else
{
    for (int i = F; i < K + F; i++) {
        x[F]--;
    }
    cajas++;
}



}



    return cajas;
}





int chocolates(int K, vector<int> &x) {
    int cajasposibles = 0;
    vector<int> xsorteado = x;
    sort(xsorteado.begin(), xsorteado.end());
   if (1<= K & K<= x.size() & x.size() <= 50) {
     bool hola = 1;
     for (int i = 0; i < x.size(); i++) {
        if (x[i] < 1 | x[i] > 1000) {hola = 0;}
     }
        if (hola == 1) {
 
            cajasposibles = calcularcajas(K, x);




        }


   }
   return cajasposibles;
}
