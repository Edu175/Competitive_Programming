#include <vector>

using namespace std;

long long bombones(int K, vector<int> &x) {
    // SOLUCION BASADA EN BUSQUEDA BINARIA EN LA RESPUESTA
    long long s = 0;
    for (int elem : x)
        s += elem;
    long long a = 0, b = s+1;
    while (b-a > 1)
    {
        long long c = (a+b)/2;
        long long total = 0;
        for (long long elem : x)
            total += min(c, elem);
        if (c <= total/K)
            a = c;
        else
            b = c;
    }
    return a;
}
