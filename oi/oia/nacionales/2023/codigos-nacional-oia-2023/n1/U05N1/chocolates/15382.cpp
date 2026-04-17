#include <string>
#include <vector>


using namespace std;

int chocolates(int K, vector<int> &x) 
{
	int res=0;
	int N;
	N=x.size();
	for (int i=0; i<N; i++) {
		while (x[i] >= K) {
			x[i]=x[i]-K;
			res=res+1;
		}
	}
	return res;
}
