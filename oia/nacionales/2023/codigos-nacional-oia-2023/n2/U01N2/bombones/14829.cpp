#include <string>
#include <vector>

using namespace std;

long long bombones(int K, vector<int> &x) {
    // AQUI SE DEBE IMPLEMENTAR LA SOLUCION
    
    long long cajas;
    int k_actual = K;
    
    for (int i = 0; i < x.size(); i++){
		for (int z = 0; z < x.size(); z++){
			while (k_actual != K){
				if (x[z] == 0){
				k_actual = k_actual - 1;
				
				}
				else{
					x[z] = x[z] - 1;
					cajas = cajas + 1;
				}
			}
		}
	}
	
	return cajas;
}
