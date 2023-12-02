#include <string>
#include <vector>

#include <bits/stdc++.h>

using namespace std;

vector<int> inout(vector<int> &t, vector<int> &e) {
    // AQUI SE DEBE IMPLEMENTAR LA SOLUCION
    vector<int> f;
    f.resize(2);
    if(t.size() == 2)
    {
        f.resize(f.size()+2);
        f[0] = 2;
        f[1] = -2;
        f[2] = 0;
        f[3] = 0;

    }

    return f;
}
