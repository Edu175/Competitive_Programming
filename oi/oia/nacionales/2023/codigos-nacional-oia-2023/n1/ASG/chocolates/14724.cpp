#include <vector>

using namespace std;

int chocolates(int K, vector<int> &x) {
    // SOLUCION BASADA EN CONDICION SOBRE LA RESPUESTA
    for(int cant = 1; ; cant++)
    {
        int total = 0;
        for (int elem : x)
            total += min(cant, elem);
        if (cant * K > total)
            return cant-1;
    }
}
