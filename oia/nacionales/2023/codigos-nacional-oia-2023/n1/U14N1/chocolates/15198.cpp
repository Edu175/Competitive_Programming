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
if (1<= K & K<= N & N <= 50) {
hola = 1;
for (int i = 0; i < N; i++) {
    
        if (x[i] < 1 | x[i] > 1000) {hola = 0;}
     }


}

return hola;
}


int chocolates(int K, vector<int> &x) {
    int cajasposibles = 0;


    sort(x.begin(), x.end());
bool hola1 = comprobar(K,x);

   if (hola1 == 1) {
int N = x.size();
int F = 0;
int P = N - K;
int Y = 0;
while (F <= P) {

if (x[F] == 0) {F++;} else
{
    Y = K + F;
    for (int i = F; i < Y; i++) {
        x[F] = x[F] - 1;
    }
    cajasposibles++;
}


        }

   }
   
   return cajasposibles;
}
