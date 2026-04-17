#include <string>
#include <vector>

using namespace std;

long long bombones(int K, vector<int> &x) {
long long suma=0;
for (int i=0; i<K;i++){
	suma=suma+x[i];
}
suma=suma/x.size;
return suma;
}
