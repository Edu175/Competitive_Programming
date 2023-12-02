#include <string>
#include <vector>
#include <algorithm>
using namespace std;

long long bombones(int K, vector <int> & x){
sort(x.begin(), x.end());

int suma=0;
int tam=x.size();
for (int j=0;j<tam;j++){
suma+=x[j];
}
long long repes=0, total=0;
while (repes<(int)suma/K){
sort(x.begin(), x.end());

for (int i=tam-1;i>tam-K-1;i--){
if (x[i]==0){
repes=(int)suma/K;
total--;
}
else{
x[i]--;
}
}
total++;
repes++;
}
return total;
}

