#include <string>
#include <vector>

using namespace std;

vector<int> hoteles(vector<int>& padre, vector<int>& tipo, vector<int>& nodo)
{
	vector<int> resultados;
	int aux;
	
	const int Q = tipo.size();
	const int P = padre.size();
	int nodoActual;
	vector<int> estados;
	estados.resize(Q, 1);
	bool existe = 0;
	
	// Por cada uno de los pedidos...
	for(int i = 0; i < Q; i++)
	{
		nodoActual = nodo[i];
		
		if(tipo[i] == estados[i])
		{
			resultados.push_back(0);
		}
		else
		{
			if(tipo[i] == 1)
			{
				resultados.push_back(1);
			}
			
			// Se quiere poner en modo WIFI.
			else
			{
				// Verificar si se rompe alguna cadena
				for(int k = 0; k < P; k++)
				{
					// Se verifica si el nodo actual existe dentro de padres.
					if(nodoActual == padre[k])
					{
						existe = 1;
						aux = padre[k];
						break;
					}
				}
				if(existe)
				{
					// Se rompe una cadena
					resultados.push_back(0);
				}
				else
				{
					resultados.push_back(1);
				}
			}
		}
	}
	return resultados;
}
