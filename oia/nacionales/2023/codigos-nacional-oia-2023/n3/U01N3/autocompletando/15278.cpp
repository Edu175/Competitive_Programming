#include <bits/stdc++.h>

using namespace std;

int autocompletando(int K, vector<string> &r1, vector<string> &r2, vector<string> &r3, string &texto) {
    int tamanoTexto = 1;
    // vector<string> vectorcito ;
    int palabrasPredichas = 0;
    // int j = 0;
    for (int i=0; i<(int)texto.size(); i++){
		if (texto[i] == ' '){
			tamanoTexto++;
			// j++;
		}
		/* else {
			vectorcito[j] = vectorcito[j] + texto[i];
		} */
	} // En este for, intento separar en "vectorcito" las palabras de "texto" y calcular la cantidad de palabras en "texto"
		if((int)r1.size() == 1){
			for (int i=0; i<tamanoTexto-2; i++){
				if (texto[i] == r1[0][i] && texto[i+1] == r2[0][i] && texto[i+2] == r3[0][i]){
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
