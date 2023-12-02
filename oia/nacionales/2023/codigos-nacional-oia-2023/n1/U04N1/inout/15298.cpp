#include <string>
#include <vector>

#include <bits/stdc++.h>

using namespace std;

vector<int> inout(vector<int> &t, vector<int> &e) {
    // AQUI SE DEBE IMPLEMENTAR LA SOLUCION
    vector<int> f;
    f.resize(2);

    if(t[0] == 1)
    {
        f.resize(f.size()+1);
        f[0] = 1;
        f[1] = -1;
        f[2] = 0;
    }
    else
    {
        f.resize(f.size()+1);
        f[0] = 1;
        f[1] = -2;
        f[2] = 0;
    }

    return f;
}
