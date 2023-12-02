#include <bits/stdc++.h>
using namespace std;

vector<int> hoteles(vector<int>& padre, vector<int>& tipo, vector<int>& nodo) {

    
    //LAS PRIMERAS SUBTAREAS SON: que todos esten conectados al nodo inicial. 15 pts
    //que el nodo i sea hijo de i-1... 10 pts
    //las otras minimizan complejidad
    
    //SOLUCION NO OPTIMA: para cada pedido veo primero si no esta en ese estado. segundo, hago el recorrido hasta llegar al 0. si alguno esta en modo wifi fuiste
   
   int N = int(padre.size());
   int Q = int(tipo.size());//cant de pedidos
   vector<int> resultados(Q);
   vector<int> estado(N, 1);
   for(int i = 0; i < Q; i++){
	   if(tipo[i] == estado[nodo[i]]) resultados[i] = 0;
	   else resultados[i] = 1;
	}
	return resultados;
}

