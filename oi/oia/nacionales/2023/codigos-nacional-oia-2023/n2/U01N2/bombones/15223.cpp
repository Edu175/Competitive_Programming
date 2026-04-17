#include <string>
#include <vector>

using namespace std;


long long bombones(int K, vector<int> &x) {
    // AQUI SE DEBE IMPLEMENTAR LA SOLUCION
    
    long long cajas;
    
    while(x[K] != 0){
		x[K] = x[K] - 1;
		cajas  = cajas + 1;
	}
    return cajas;
}
