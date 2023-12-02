#include <string>
#include <vector>

using namespace std;

int chocolates(int K, vector<int> &x) 
{
	int res;
	int N = x.size();
	for(int i = 0; i <= N; i++) {
		while( x[i] >= 0)
		{
		x[i] = x[i] - 1;
		res = res + 1;
		}
	}
	return res;
}
