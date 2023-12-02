#include <string>
#include <vector>

using namespace std;


long long bombones(int K, vector<int> &x) {
    // AQUI SE DEBE IMPLEMENTAR LA SOLUCION
    
    long long cajas;
    
    for (int i = 0; i < x.size(); i++){
		x[i] = x[i] - 1;
		cajas = cajas + 1;
	}
    return cajas;
}
