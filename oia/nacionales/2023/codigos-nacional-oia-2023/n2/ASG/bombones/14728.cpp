#include <vector>
#include <functional>
#include <algorithm>

using namespace std;

#define forsn(i,s,n) for(int i=int(s);i<int(n);i++)

#define ALL(c) begin(c),end(c)

long long bombones(int K, vector<int> &x) {
    // SOLUCION BASADA EN FORMULA CERRADA
    long long s = 0;
    for (int num : x)
        s += num;
    sort(ALL(x), greater<int>());
    long long ret = s/K;
    forsn(i,1,K)
    {
        s -= x[i-1];
        ret = min(ret, s/(K-i));
    }
    return ret;
}
