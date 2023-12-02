#include <bits/stdc++.h>

using namespace std;

int autocompletando(int K, vector<string> &r1, vector<string> &r2, vector<string> &r3, string &texto) {
    int tamanoTexto = 1;
    int palabrasPredichas = 0;
    vector<int> valores;
    valores[0] = 0;
    for (int i=0; i<(int)texto.size(); i++){
		if (texto[i] == ' '){
			valores.push_back(i);
			tamanoTexto++;
		}
	}
		if((int)r1.size() == 1){
			for (int i=0; i<tamanoTexto-2; i++){
				if (texto[valores[i]+1] == r1[0][0]) {
					int j = valores[i]+2;
					int k = 1;
					while (j <= valores[i+1]){
						if (texto[j] == r1[0][k]) {
							j++;
							k++;
							if (j == valores[i+1]){
								k = 0;
							}
						}
						else {
							break;
						}
					}
					if (k == 0 && texto[valores[i+1]+1] == r2[0][0]) {
						j = valores[i+1]+2;
						k = 1;
						while (j <= valores[i+2]) {
							if (texto[j] == r2[0][k]){
								j++;
								k++;
								if (j == valores[i+2]){
									k = 0;
								}
							}
						}
						if (k == 0 && texto[valores[i+2]+1] == r3[0][0]) {
							j = valores[i+2]+2;
							k = 1;
							while (j <= valores[i+3]) {
								if (texto[j] == r3[0][k]) {
									j++;
									k++;
									if (j == valores[i+3]) {
										palabrasPredichas++;
										break;
									}
								}
							}
						 }
						 else {
							 break;
						 }
					}
					else {
						break;
					}
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
