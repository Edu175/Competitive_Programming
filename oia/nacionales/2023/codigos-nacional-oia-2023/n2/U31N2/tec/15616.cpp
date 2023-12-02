#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> tab;

bool estaControlado(int pais, vector<int> controlados)
{
	for (int i = 0; i < int(controlados.size()); i++)
	{
		if (pais == controlados[i])
		{
			return true;
		}
	}
	return false;
}

void tablero(int N, vector<int> &A, vector<int> &B) {
    // AQUI SE DEBE IMPLEMENTAR LA SOLUCION
    tab.resize(N+1);
    for (int i = 0; i < int(A.size()); i++)
    {
		tab[A[i]].push_back(B[i]);
		tab[B[i]].push_back(A[i]);
	}
}

int con_quien_comercio(vector<int> &controlados) {
    // AQUI SE DEBE IMPLEMENTAR LA SOLUCION
    sort(controlados.begin(),controlados.end());
    for (int i = 0; i < int(controlados.size()); i++)
    {
		vector<int> pais = tab[controlados[i]];
		for (int j = 0; j < int(pais.size()); j++)
		{
			if (!estaControlado(pais[j],controlados))
			{
				return pais[j];
			}
		}
	}
	return -1;
}
