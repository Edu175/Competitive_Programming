#include <bits/stdc++.h>
using namespace std;

//ES MUCHO MAS SIMPLE: SI HAY UNO PRENDIDO, O ES TU PADRE O ES TU HIJO Y NO SE PUEDE

vector<int> hoteles(vector<int>& padre, vector<int>& tipo, vector<int>& nodo) {

   int N = int(padre.size())+1;
   int Q = int(tipo.size());//cant de pedidos
   vector<int> resultados(Q);
   vector<int> estado(N, 1);
   int k = 0;//cant en wifi
	bool hecho = false;
   for(int i = 0; i < Q; i++){
	  if(tipo[i] == 1 and estado[nodo[i]] == 0 and hecho == false){//pasa de wifi a transmision, no drama
			estado[nodo[i]] = 1;
			k--;
			resultados[i] = 1;
			hecho = true;
	}
	 if(tipo[i] == 1 and estado[nodo[i]] == 1 and hecho == false){//pasa de wifi a transmision, no drama
			resultados[i] = 0;
			hecho = true;
	}
	if(tipo[i] == 0 and estado[0] == 0 and hecho == false){
		resultados[i] = 0;
		hecho = true;
		}
		if(tipo[i] == 0 and estado[nodo[i]] == 0 and hecho == false){
		resultados[i] = 0;
		hecho = true;
		}
	if(nodo[i] != 0 and tipo[i] == 0 and hecho == false){
		k++;
		resultados[i] = 1;
		estado[nodo[i]] = 0;//pasa a wifi	
		hecho = true;
	}
	if(nodo[i] == 0 and tipo[i] == 0 and hecho == false and k == 0){
		k++;
		resultados[i] = 1;
		estado[nodo[i]] = 0;//pasa a wifi	
		hecho = true;
	}
	if(nodo[i] == 0 and tipo[i] == 0 and hecho == false and k > 0){
		
		resultados[i] = 0;
		
	}
	hecho = false;

}
	return resultados;
}
