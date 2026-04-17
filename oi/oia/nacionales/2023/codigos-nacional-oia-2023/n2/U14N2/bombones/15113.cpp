#include <string>
#include <vector>

using namespace std;
long long bombones(int K, vector<int> &x) {
int suma=0;
for (int i=0;i<K;i++){
	suma=x[i]+x[i+1];

	}
	suma=suma/K-1;
return suma;
}


