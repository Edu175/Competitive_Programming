#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long bombones(int K, vector<int> &x) {
	long long result = K / int(x.size());
	return result;
	if (K==1 || int(x.size()) == 1)
	{	
		long long result = 0;
		for (int i = 0; i < int(x.size()); i++)
		{
			result+=x[i];
		}
		return result;
	}
	
    sort(x.begin(),x.end());
    int N = int(x.size());
    //long long result = 0;
    long long counter = 0;
    long long index = 0; //Primer index mayor a 0;
    //Ordenar de mayor a menor.
    for (int i = 0; i < N/2; i++)
    {
		int aux = 0;
		aux = x[i];
		x[i] = x[N-i-1];
		x[N-i-1] = aux;
	}

	for (int j = 0; j < N; j=index)
	{
		if(x[j]>0)
		{
			x[j]--;
			counter++;
			j++;
		}
		else 
		{
			index = j+1;
		}
		if (counter == K)
		{
			counter = 0;
			result++;
			j = index;
		}
		if (index == N-K+1)
		{
			return result;
		}
	}
	return result;
}
