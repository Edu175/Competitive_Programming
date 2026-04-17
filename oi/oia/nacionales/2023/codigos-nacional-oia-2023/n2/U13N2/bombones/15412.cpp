#include <string>
#include <vector>
#include <algorithm>
using namespace std;

long long bombones(int K, vector <int> & x){
sort(x.begin(), x.end());

int suma=0;
for (int j=0;j<x.size();j++){
suma+=x[j];
}
int repes=0, total=0;
while (repes<(int)suma/K){
sort(x.begin(), x.end());

for (int i=x.size()-1;i>x.size()-K-1;i--){
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

