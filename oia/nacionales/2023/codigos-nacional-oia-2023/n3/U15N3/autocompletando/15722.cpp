#include <string>
#include <vector>

using namespace std;

string palabra(int indice, string texto);
int autocompletando(int K, vector<string> &r1, vector<string> &r2, vector<string> &r3, string &texto)
{
	// los pares de palabras r1[i] y r2[i] recomiendan r3[i].
	// el string texto va a tener que ser corroborado. 
	
	// Se crean 2 strings
	// Se les dan los valores de palabra 0 y palabra 1
	
	/*
	 * Repetir
	 * 		Existe P1 dentro de R1?
	 * 		SI
	 * 			Existe P2 dentro de R2?
	 * 			SI 
	 * 				Existe una palabra siguiente a P2?
	 * 				SI
	 * 					Es igual a R3?
	 * 					SI
	 * 						Seguir con esa palabra (i1++, i2++)
	 * 					NO
	 * 						return 0
	 * 				NO
	 * 					return 1
	 * 			NO
	 * 				Hacer nada.
	 * 		NO
	 * 			return 0
	 * 
	 * */
	 int itr = 0;
	 string p1, p2;
	 int i1, i2;
	 i1 = 0;
	 i2 = 1;
	 const int Q = r1.size();
	 bool existe1, existe2;
	 
	 while(true)
	 {
		 
		 p1 = palabra(i1, texto);
		 p2 = palabra(i2, texto);
		 
		 existe1 = 0;
		 existe2 = 0;
		 
		 // Corroborar si existe P1 dentro de R1
		 for(int i = 0; i < Q; i++)
		 {
			 if(p1 == r1[i])
			 {
				 existe1 = 1;
				 // La palabra existe
				 // Verificar si existe P2 dentro de R2
				 for(int j = 0; j < Q; j++)
				 {
					 if(p2 == r2[j])
					 {
						 // Hay una coincidencia con las dos palabras.
						 // Si existe una siguiente palabra...
						 if(i2 + 1 <= K)
						 {
							 // Si existe la palabra i2+1 dentro de R3...
							 for(int k = 0; k < Q; k++)
							 {
								 if(palabra(i2+1, texto) == r3[k])
								 {
									 // Se sigue con la siguiente palabra.
									 existe2 = 1;
								 }
							 }
							 if(existe2)
							 {
								 i1++;
								 i2++;
							 }
							 else
							 {
								 return 0;
							 }
						 }
						 else
						 {
							 return 1;
						 }
					 }
				 }
			 }
		 }
		 if(!existe1)
		 {
			 return 0;
		 }
	 }
	
}

string palabra(int indice, string texto)
{
	// Retorna la palabra indice del string texto. 
	int espacios = 0;
	string buffer;
	for(int i = 0; i < texto.length(); i++)
	{
		if(espacios == indice)
		{
			while(texto[i] != ' ' && texto[i] != '\0')
			{
				buffer.push_back(texto[i]);
				i++;
			}
			return buffer;
		}
		if(texto[i] == ' ')
		{
			espacios++;
		}
	}
	return "";
	
}
