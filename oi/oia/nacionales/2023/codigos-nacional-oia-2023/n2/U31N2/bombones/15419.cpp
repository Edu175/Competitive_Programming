#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long bombones(int K, vector<int> &x) {
    sort(x.begin(),x.end());
    long long result = 0;
    int N = int(x.size());
    for (int i = 0; i < N/2; i++)
	{
		int aux = 0;
		aux = x[i];
		x[i] = x[N-i-1];
		x[N-i-1] = aux;
	}
	
	for (int i = 0; i < N; i++)
	{
		int min = 999999;
		int index = i;
		for (int j = i; j < K+i; j++)
		{
			if (x[j] < min)
			{
				min = x[j];
				index = j;
			}
		}
		for (int j = i; j < K+i; j++)
		{
			x[j]-=min;
		}
		result+=min;
		
		int aux = x[i];
		x[i]=x[index];
		x[index]=aux;
	}
	return result;
}
