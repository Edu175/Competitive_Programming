#include <string>
#include <vector>
#include <algorithm>
using namespace std;

void restaraK(vector <int> x, int K, int ultimo){
for (int i=ultimo;i<ultimo+K;i++){
x[i]--;
}
}
bool sePuede(vector <int> x, int K, int &ultimo){
if (ultimo+K>=x.size()){
return false;
}
if (x[ultimo]==0){
ultimo++;
return false;
}
else {
return true;}
}
long long bombones(int K, vector<int> &x){
sort (x.begin(), x.end());
int ultimo=0;
int repeticiones=0, total=0;
int suma=0;
for (int j=0;j<x.size();j++){
    suma+=x[j];
}
while (repeticiones<suma/K){
if (sePuede(x, K, ultimo)){
restaraK(x, K, ultimo);
total++;
}
repeticiones++;
}
return total;
}

