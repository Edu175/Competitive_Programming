#include <string>
#include <vector>

using namespace std;

long long bombones(int K, vector<int> &x) {
    int size= x.size();
    int X=1;

        int u=0;
    for (int i=-1 ; i<size ; i++){

        X+= x[i];

    }
    X=X-1;
return X;
}
