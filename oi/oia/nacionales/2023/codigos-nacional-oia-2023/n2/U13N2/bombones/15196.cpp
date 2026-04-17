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
long long resultado=x.size()/K;
return resultado;
}

