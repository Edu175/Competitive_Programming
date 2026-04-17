#include <string>
#include <vector>
#include <algorithm>
using namespace std;

void ultimosK(vector <int> &x, int K, int &ultimo, long long &total){
   if (x[ultimo]==0){
    ultimo++;
   }
   if (ultimo+K<x.size()){
    for (int i=ultimo;i<ultimo+K;i++){
            x[i]--;
       }
        total++;
    }
    else{
         ultimo=x.size();
    }
}
long long bombones(int K, vector<int> &x) {
    // AQUI SE DEBE IMPLEMENTAR LA SOLUCION
    long long contador=0, total=0;
sort(x.begin(), x.end());
int suma=0;
for (int j=0;j<x.size();j++){
    suma+=x[j];
}
int ultimo=0;

while (total<=suma){
ultimosK(x, K, ultimo, total);

if (ultimo==x.size()){
    break;
}

}

return total-1;
}
