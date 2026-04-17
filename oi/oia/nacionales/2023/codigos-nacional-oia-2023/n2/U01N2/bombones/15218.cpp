#include <string>
#include <vector>

using namespace std;


long long bombones(int K, vector<int> &x) {
    // AQUI SE DEBE IMPLEMENTAR LA SOLUCION
    
    long long cajas;
    
    while(x[0] != 0){
		x[0] = x[0] - 1;
		cajas  = cajas + 1;
	}
    return cajas;
}
