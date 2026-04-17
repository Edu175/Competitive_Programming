#include <vector>
#include <algorithm>

using namespace std;

#define forsn(i,s,n) for(int i=int(s);i<int(n);i++)

#define ALL(c) begin(c),end(c)

int chocolates(int K, vector<int> &x) {
    // SOLUCION BASADA EN FORMULA CERRADA
    int s = 0;
    for (int num : x)
        s += num;
    sort(ALL(x));
    reverse(ALL(x));
    int ret = s/K;
    forsn(i,1,K)
    {
        s -= x[i-1];
        ret = min(ret, s/(K-i));
    }
    return ret;
}
