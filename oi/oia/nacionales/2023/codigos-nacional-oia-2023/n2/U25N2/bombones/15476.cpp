#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long bombones(int K, vector<int> &x) {
    long long tot = 0;
    bool noCero = true;

    if (x.size() == 1) return x[0] / K;

    while(noCero)
    {
        sort(x.begin(), x.end());
        reverse(x.begin(), x.end());
        int cant = x[K-1];

        if(cant > 0) {
            for(int i = 0; i < K; i++)
            {
                x[i] -= cant;
                tot++;
            }
        }

        sort(x.begin(), x.end());
        reverse(x.begin(), x.end());

        for(int i = 0; i < K; i++)
        {
            if (x[i] == 0) {
                noCero = false;
                break;
            }
            x[i]--;
        }
        tot++;
    }

    return tot-3;
}
