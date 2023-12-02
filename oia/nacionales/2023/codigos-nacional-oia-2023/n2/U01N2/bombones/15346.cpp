#include <string>
#include <vector>

using namespace std;


long long bombones(int K, vector<int> &x) {
    // AQUI SE DEBE IMPLEMENTAR LA SOLUCION
    
    long long cajas;
    int j = 0;
    
    while(x[j] != x.size()){
		x[j] = x[j] - 1;
		cajas = cajas + 1;
		j++;
	}
    return cajas;
}
