#include <bits/stdc++.h>
using namespace std;

int autocompletando(int K, vector<string> &r1, vector<string> &r2, vector<string> &r3, string &texto){
	//primero separo las palabras en orden en un vector
	//si n = 01 es facil creo. para cada tres palabras veo si coinciden con la regla y listo, sino es que las introdujo manual y retrocede k. si k queda en negativo es que no se puede predecir
	vector<string> palabras(1, "");
	int n = int(texto.size());
	for(int i = 0; i < n; i++){//generamos las palabras
		string l = " ";
		l[0] = texto[i];
		if(l == " ") palabras.push_back("");
		else palabras[int(palabras.size())-1].push_back(l[0]); 
	}
	K -=2;//si o si se usan las primeras dos de k
	//llega hasta palabras.size-2 porque vamos a trabajar con predicciones:
	for(int i = 0; i < int(palabras.size())-2; i++){
		bool esta = false;
		for(int j = 0; j < int(r1.size()); j++){
		 if((palabras[i] == r1[j]) and (palabras[i+1] == r2[j]) and (palabras[i+2] == r3[j])) esta = true;
	 }
		if(esta == false) K--; 
	}

	if(K > -1) return 1;
	return 0;
}

//ES LO MISMO PERO PARA CADA PALABRA TENGO QUE VER MAS REGLAS
