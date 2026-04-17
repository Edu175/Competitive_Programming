#include <string>
#include <vector>

#include <bits/stdc++.h>

using namespace std;

int chocolates(int K, vector<int> &x) {
    // AQUI SE DEBE IMPLEMENTAR LA SOLUCION
    int f = 0;
    vector<int> y;
    y.resize(x.size());
    int c = 0;

    for(int i = 0; i < y.size(); ++i)
    {
        y[i] = x[i];
    }
    for(int i = 0; i < x.size(); ++i)
    {
        c = 0;
        for(int b = 0; b < y.size(); ++b)
        {
            if(y[b] > 0)
            {
                y[b] = y[b] -1;
            }
            c = c+1;
        }
        if(c = K)
        {
            f = f+1;
        }
    }
    return f;
}
