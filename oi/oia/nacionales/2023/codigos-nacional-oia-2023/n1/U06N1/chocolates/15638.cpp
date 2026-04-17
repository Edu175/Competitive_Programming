#include <string>
#include <vector>

using namespace std;

int chocolates(int K, vector<int> &x) {

    int z=0;
    for (int i=0; i<x.size(); i++)
    {
        z=z+x[i];
    }
    return z/K;
}
