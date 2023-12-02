#include <string>
#include <vector>

#include <bits/stdc++.h>

using namespace std;

int predictivo(vector<string> &r1, vector<string> &r2, vector<string> &r3, string &texto) {
    // AQUI SE DEBE IMPLEMENTAR LA SOLUCION
    int f = 0;
    for(int i = 0; i < texto.size(); ++i)
    {
        if(texto[i] == r1[0][0] && texto[i+2] == r2[0][0])
        {
            f = 1;
            return 1;
        }
    }
    return f;
}
