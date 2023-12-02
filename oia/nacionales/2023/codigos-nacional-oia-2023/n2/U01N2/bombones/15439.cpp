#include <string>
#include <vector>

using namespace std;


long long bombones(int K, vector<int> &x) {
    // AQUI SE DEBE IMPLEMENTAR LA SOLUCION
    
    long long cajas;
    int j = 0;
    
    while (j != x.size()){
		for(int i = 0; i < x.size(); i++){
			if (x[i] == 0){
				j = j + 1;
			}
			else{
				x[i] = x[i] - 1;
				cajas = cajas + 1;
			}
		}
		j++;
	}
    return cajas;
}
