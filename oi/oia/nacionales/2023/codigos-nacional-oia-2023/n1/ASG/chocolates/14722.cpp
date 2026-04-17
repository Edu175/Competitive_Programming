#include <vector>

using namespace std;

int chocolates(int K, vector<int> &x) {
    // SOLUCION ESPECIFICA PARA K=2
    int s = 0;
    int maxim = 0;
    for (int elem : x)
    {
        s += elem;
        maxim = max(maxim, elem);
    }
    return min(s/K, s - maxim);
}
