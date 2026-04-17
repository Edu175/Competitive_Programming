#include <string>
#include <vector>
#include <algorithm>
using namespace std;

long long bombones(int K, vector<int> &x) {
    // AQUI SE DEBE IMPLEMENTAR LA SOLUCION
    long long contador=0, total=0;
sort (x.begin(), x.end());

for (int i=0;i<x.size();i++){
total+=x[i];

}
return total;
}
