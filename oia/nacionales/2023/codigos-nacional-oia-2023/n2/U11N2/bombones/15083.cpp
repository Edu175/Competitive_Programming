#include <string>
#include <vector>
#include <algorithm>
using namespace std;

long long bombones(int K, vector<int> &x) {
    long long X=0;
    int cajas=0;
    int size=x.size();
    vector<int> caja(size);

    for (int i=0 ; i<size ; i++)
    while (caja[i]<K){
        sort(x.begin(), x.end());
        x[0]--;
        caja[i]++;
    }
    cajas++;

X=cajas;
return X;
}
