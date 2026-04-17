#include <string>
#include <vector>

#include <bits/stdc++.h>

using namespace std;

int predictivo(vector<string> &r1, vector<string> &r2, vector<string> &r3, string &texto) {
    // AQUI SE DEBE IMPLEMENTAR LA SOLUCION
    vector<char> v;
    for(int i = 0; i<texto.size(); ++i)
    {
        v.push_back(texto[i]);
        i=i+1;
    }
    int f = 0;
    for(int i = 0; i<v.size(); ++i)
    {
        int f = 0;
        for(int a = 0; a < r1.size(); ++a)
        {
            if(r1[a][0] == v[i] && r2[a][0] == v[i+1])
            {
                f = 1;
            }
        }
    }
    return f;
}
