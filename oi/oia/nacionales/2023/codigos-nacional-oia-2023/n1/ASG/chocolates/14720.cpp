#include <vector>

using namespace std;

#define forn(i,n) for(int i=0;i<int(n);i++)
#define SIZE(c) int((c).size())

int chocolates(int K, vector<int> &x) {
    // SOLUCION MENOS EFICIENTE BASADA EN ELEGIR LOS K MAS GRANDES CADA VEZ
    const int N = SIZE(x);
    int ret = 0;
    bool seguir = true;
    while (seguir)
    {
        // BUBBLE SORT DE MAYOR A MENOR
        forn(i,N)
        forn(j,N-1)
        if (x[j] < x[j+1])
            swap(x[j], x[j+1]);
        // USAR LOS K MAS GRANDES
        forn(i,K)
        if (x[i] <= 0)
            seguir = false;
        else
            x[i]--;
        if (seguir)
            ret++;
    }
    return ret;
}
