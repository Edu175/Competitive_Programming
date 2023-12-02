#include <string>
#include <vector>

#include <bits/stdc++.h>

using namespace std;

vector<int> inout(vector<int> &t, vector<int> &e) {
    // AQUI SE DEBE IMPLEMENTAR LA SOLUCION
    vector<int> f;
    f.resize(2);
    if(t.size() == 1)
    {
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
        f[0] = 2;
        f[1] = -2;
        f[2] = 0;
    }
    }
    else if(t.size() == 2)
    {
        for(int i = 0;i < e.size(); ++i)
        {
            if (t[i] == 2)
            {
                f.resize(f.size()+1);
                f[0] = f[0]+1;
                f[1] = f[1]-1;
                f[f.size()-1] = 0;
            }
            if (t[i] == 1)
            {
                f.resize(f.size()+1);
                f[0] = f[0]+1;
                f[1] = f[1]-1;
                f[f.size()-1] = 0;
            }
        }
    }

    return f;
}
