#include <string>
#include <vector>

using namespace std;

long long bombones(int K, vector<int> &x) {
    long long max=0;
    for(int i=0;i<x.size();i++){
        max=max+x[i];
    }
    return max;
}
