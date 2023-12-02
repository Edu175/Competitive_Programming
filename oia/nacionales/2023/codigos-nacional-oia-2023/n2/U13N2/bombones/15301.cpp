#include <string>
#include <vector>
#include <algorithm>
using namespace std;
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
void invertirVec(vector<int>&x){
vector<int> aux;
for (int i=x.size()-1;i>=0;i--)
    aux.push_back(x[i]);
    x=aux;
}
long long bombones(int K, vector <int> & x){
sort(x.begin(), x.end());

int suma=0;
for (int j=0;j<x.size();j++){
suma+=x[j];
}
int repes=0, total=0;
while (repes<(int)suma/K){
sort(x.begin(), x.end());

for (int i=x.size();i>x.size()-K;i--){
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

