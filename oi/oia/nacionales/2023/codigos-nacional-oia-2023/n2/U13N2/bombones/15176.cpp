#include <string>
#include <vector>
#include <algorithm>
using namespace std;

long long bombones(int K, vector <int> & x){
sort(x.begin(), x.end());
invertirVec(x);
int suma=0;
for (int j=0;j<x.size();j++){
suma+=x[j];
}
int repes=0, total=0;
while (repes<(int)suma/K){
sort(x.begin(), x.end());
invertirVec(x);
for (int i=0;i<K;i++){
if (x[i]==0){
repes=(int)suma/K;
total--;
}
else{
x[i]--;
}
}
total++;
}
return total;
}

