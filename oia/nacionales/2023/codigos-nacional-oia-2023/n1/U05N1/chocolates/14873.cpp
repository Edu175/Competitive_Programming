#include <string>
#include <vector>

using namespace std;

int chocolates(int K, vector<int> &x) 
{
	int N = x.size();
	for(int i = 0; i <= K; i++) {
		while( x[i] >= N)
		{
			x[i] = x[i] - 1;
		}
	}
return N;
}
