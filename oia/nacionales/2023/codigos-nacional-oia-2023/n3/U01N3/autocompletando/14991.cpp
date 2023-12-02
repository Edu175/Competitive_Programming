#include <string>
#include <vector>

using namespace std;

int autocompletando(int K, vector<string> &r1, vector<string> &r2, vector<string> &r3, string &texto) {
    int tamanoTexto = 1;
    vector<string> vectorcito;
    int palabrasPredichas = 0;
    int j = 0;
    int k = 0;
    for (int i=0; i<(int)texto.size(); i++){
		if (texto[i] == ' '){
			tamanoTexto++;
			j++;
			k = 0;
		}
		else {
			vectorcito[j][k] = texto[i];
			k++;
		}
	}// En este for, intento separar en "vectorcito" las palabras de "texto" y calcular la cantidad de palabras en "texto"
		if((int)r1.size() == 1){
			for (int i=0; i<tamanoTexto-2; i++){
				if (vectorcito[i] == r1[0] && vectorcito[i+1] == r2[0] && vectorcito[i+2] == r3[0]){
					palabrasPredichas++;
				}
			}
			if (palabrasPredichas + K >= tamanoTexto){
				return 1;
			}
			else {
				return 0;
			}
		}
}
