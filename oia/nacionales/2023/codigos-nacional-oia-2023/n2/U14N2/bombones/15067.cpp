#include <string>
#include <vector>

using namespace std;

long long bombones(int K, vector<int> &x) {
long long suma=0;
for (int i=0; i<K;i++){
	suma=suma+x[i]+x[1]+x[2]+x[3]+x[4];
}
return suma;
}
