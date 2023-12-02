#include <string>
#include <vector>
#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <algorithm>


using namespace std;

bool comprobar(int K, vector<int> &x) {
bool hola = 0;
int N = x.size();
if (1<= K && K<= N && N <= 50) {
hola = 1;
for (int i = 0; i < N; i++) {
    
        if (x[i] < 1 || x[i] > 1000) {hola = 0;}
     }


}

return hola;
}


int chocolates(int K, vector<int> &x) {
    int cajasposibles = 0;
    vector<int> xsorteado = x;


    sort(xsorteado.begin(), xsorteado.end());
bool hola1 = comprobar(K,x);

   if (hola1 == 1) {
     

int N = x.size();
            int cajas = 0;
int F = 0;
int K = 0;
while (F <= N - K) {

if (x[F] == 0) {F++;} else
{
    for (int i = F; i < K + F; i++) {
        x[F]--;
    }
    cajas++;
}


        }
cajasposibles = cajas;

   }
   
   return cajasposibles;
}
