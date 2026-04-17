#include <bits/stdc++.h>
using namespace std;

vector<int> hoteles(vector<int>& padre, vector<int>& tipo, vector<int>& nodo) {

    
    //LAS PRIMERAS SUBTAREAS SON: que todos esten conectados al nodo inicial. 15 pts
    //que el nodo i sea hijo de i-1... 10 pts //pq y miero si el top de la pq es menor al que tengo
    //las otras minimizan complejidad
    
    //SOLUCION NO OPTIMA: para cada pedido veo primero si no esta en ese estado. segundo, hago el recorrido hasta llegar al 0. si alguno esta en modo wifi fuiste
   
   int N = int(padre.size())+1;
   int Q = int(tipo.size());//cant de pedidos
   vector<int> resultados(Q);
   vector<int> estado(N, 1);
   int k = 0;//cant en wifi
   for(int i = 0; i < Q; i++){
	   if(tipo[i] == estado[nodo[i]]) resultados[i] = 0;
	   else{
		    resultados[i] = 1;
		   }
	   if((estado[0] == 0) and (tipo[i] == 0)) resultados[i] = 0;
	   if(nodo[i] == 0 and tipo[i] == 0){
			if(k > 0) resultados[i] = 0;
			if(resultados[i] == 1) estado[nodo[i]] = tipo[i];
		}
	   
	}
	return resultados;
}
