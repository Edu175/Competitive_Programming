#include <string>
#include <vector>

#include <bits/stdc++.h>

using namespace std;

int chocolates(int K, vector<int> &x) {
    // AQUI SE DEBE IMPLEMENTAR LA SOLUCION
    int f = 0;
    int b = 0;
    int c = 0;
    if(K==2)
    {

    for(int i = 0; i < x.size(); ++i)
    {
        if (x[i] > K)
        {
            x[i] == K;
        }
        f = f + (x[i]/K);
    }
    if(x.size() < K)
    {
        f = 0;
    }
    }
    return f;
}
