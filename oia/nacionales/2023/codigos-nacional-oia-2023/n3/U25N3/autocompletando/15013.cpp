#include <string>
#include <vector>

using namespace std;

int autocompletando(int K, vector<string> &r1, vector<string> &r2, vector<string> &r3, string &texto) {
	
	int siguiente,palabraf;
	
	for (int i=0; i<(texto.size());i++){
		
		palabraf = ((texto.size()[i])-2);
		
		for ( int u=0; u<(palabraf.size()); u++){
			r1 = palabraf[1];
			r2 = palabraf[2];
		
		if (r1<r2){
		
		siguiente = r3;
		
		}
	}
}
	
	return siguiente; // AQUI SE DEBE IMPLEMENTAR LA SOLUCION
}
