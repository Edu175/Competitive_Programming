#include <string>
#include <vector>

using namespace std;

long long bombones(int K, vector<int> &x) {
    // AQUI SE DEBE IMPLEMENTAR LA SOLUCION
    int sum = 0;
    if (K == 1) {
        for(auto c : x)
        {
            sum++;
        }
    }
    return sum;
}
