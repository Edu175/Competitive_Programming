#include <string>
#include <vector>

using namespace std;

int chocolates(int K, vector<int> &x) {
    int largo = x.size();
    if((largo == 1)||(K == 1)){
        return x[0];
    }
}