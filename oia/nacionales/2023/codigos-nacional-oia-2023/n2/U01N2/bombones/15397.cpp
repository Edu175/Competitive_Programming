#include <string>
#include <vector>

using namespace std;


long long bombones(int K, vector<int> &x) {
    // AQUI SE DEBE IMPLEMENTAR LA SOLUCION
    
    long long cajas;
    
    for (int i = 0; i < x.size(); i++){
		for (int z = 0; z < x.size(); z++){
			if (x[z] != 0){
				x[z] = x[z] - 1;
				cajas = cajas + 1;
			}
		}
	}
    return cajas;
}
