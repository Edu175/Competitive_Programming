#include <string>
#include <vector>

using namespace std;


long long bombones(int K, vector<int> &x) {
    // AQUI SE DEBE IMPLEMENTAR LA SOLUCION
    
    long long cajas;
    
    for (long long i = 0; i < x.size(); i++){
		while(x[i] != 0){
			x[i] = x[i] - 1;
			cajas = cajas + 1;
			}
	}
    
	
    return cajas;
}
