#include <string>
#include <vector>

#include <bits/stdc++.h>

using namespace std;

int chocolates(int K, vector<int> &x) {
    // AQUI SE DEBE IMPLEMENTAR LA SOLUCION
    int f = 0;
    for(int i = 0; i < x.size(); ++i)
    {
        if (x[i] > K)
        {
            x[i] == K;
        }
        f = f + (x[i]/K);
    }
    return f;
}
