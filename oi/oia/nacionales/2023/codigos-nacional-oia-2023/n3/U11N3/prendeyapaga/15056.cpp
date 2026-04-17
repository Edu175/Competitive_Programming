#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int w = -1;
vector<int> ret;

vector<int> hoteles(vector<int>& padre, vector<int>& tipo, vector<int>& nodo) {
    // AQUI SE DEBE IMPLEMENTAR LA SOLUCION
    for (int i = 0; i < tipo.size(); i++) {
        if (tipo[i] == 0) {
            if (w == -1) {
                w = nodo[i];
                ret.push_back(1);
            }
            else {
               ret.push_back(0); 
            }
        }
        else {
            if (w == nodo[i]) {
                w = -1;
                ret.push_back(1);
            }
            else {
               ret.push_back(0); 
            }
        }
    }
    
    return ret;
}
