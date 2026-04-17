#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long bombones(int K, vector<int> &x) {
    long long tot = 0;

    if (x.size() == 1) return x[0] / K;

    sort(x.begin(), x.end());
    reverse(x.begin(), x.end());

    int cant = x[K-1];

    while(cant > 0)
    {
        for(int i = 0; i < K; i++)
        {
            x[i] -= cant;
        }

        tot += cant;
        sort(x.begin(), x.end());
        reverse(x.begin(), x.end());
        cant = x[K-1];
    }

    return tot;
}
