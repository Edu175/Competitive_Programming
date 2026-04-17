#include <string>
#include <vector>

using namespace std;

long long bombones(int K, vector<int> &x) {
    int n = x.size();
    if(K == 1)
    {
        long long aux = 0;
        for(int i = 0; i<n; i++)
        {
            aux += x[i];
        }
        return aux;
    }

}
