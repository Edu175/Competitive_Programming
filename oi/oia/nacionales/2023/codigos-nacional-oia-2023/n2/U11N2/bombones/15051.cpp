#include <string>
#include <vector>
#include <algorithm>
using namespace std;

long long bombones(int K, vector<int> &x) {
    long long X=0;
    int cajas=0;
    vector<int> caja;

    while (caja[1]<K){
        sort(x.begin(), x.end());
        x[0]--;
        caja[1]++;
    }
    cajas++;

X=cajas;
return X;
}
