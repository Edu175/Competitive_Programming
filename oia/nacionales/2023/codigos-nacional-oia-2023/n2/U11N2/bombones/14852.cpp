#include <string>
#include <vector>

using namespace std;

long long bombones(int K, vector<int> &x) {
    int size = x.size();
    long long X=0;
    for (int i=0 ; i<size ; i++){

        X+= x[i];

    }
return X;
}
