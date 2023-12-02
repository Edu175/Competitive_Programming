#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long bombones(int K, vector<int> &x) {
    // AQUI SE DEBE IMPLEMENTAR LA SOLUCION
    int N = int(x.size());
    long long result = 0;
    for (int j = 0; j < N-K+1; j++)
    {
		//Ordenar de mayor a menor.
		sort(x.begin(),x.end());
		for (int i = 0; i < N/2; i++)
		{
			int aux = 0;
			aux = x[i];
			x[i] = x[N-i-1];
			x[N-i-1] = aux;
		}
		
		int min = x[K-1];
		for (int i = 0; i < K; i++)
		{
			x[i]-=min;
		}
		result+=min;
	}
	return result;
}
