#include <bits/stdc++.h>

using namespace std;

int autocompletando(int K, vector<string> &r1, vector<string> &r2, vector<string> &r3, string &texto) {
	int palabrasPredichas = 0;
	int tamanoTexto = (int)texto.size();
	int tamanotexto = (tamanoTexto/2) + 1;
	for (int i=0; i<tamanoTexto-4; i+=2){
		if (texto[i] == r1[0][0] && texto[i+2] == r2[0][0] && texto[i+4] == r3[0][0]){
			palabrasPredichas++;
		}
	}
	if (palabrasPredichas + K >= tamanotexto){
		return 1;
	}
	else {
		return 0;
	}
}
