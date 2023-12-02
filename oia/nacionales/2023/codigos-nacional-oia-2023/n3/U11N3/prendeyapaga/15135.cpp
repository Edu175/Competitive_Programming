#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int p_w = 0;
int sons_w = 0;
vector<bool> is_wifi;
vector<int> ret;

vector<int> hoteles(vector<int>& padre, vector<int>& tipo, vector<int>& nodo) {
    // AQUI SE DEBE IMPLEMENTAR LA SOLUCION
    is_wifi.resize(padre.size()+1, false);
    for (int i = 0; i < tipo.size(); i++) {
        // for (auto a : is_wifi) cout << a << " ";
        // cout << endl;
        if (tipo[i] == 0) {
            // cout << "PRENDO " << nodo[i] << " ";
            if (nodo[i] == 0) {
                if (sons_w == 0 && p_w == 0) {
                    p_w = 1;
                    ret.push_back(1);
                    // cout << "BIEN";
                }
                else {
                    ret.push_back(0);
                    // cout << "MAL";
                }
            }
            else {
                if (p_w == 0 && !is_wifi[nodo[i]]) {
                    sons_w++;
                    ret.push_back(1);
                    is_wifi[nodo[i]] = true;
                    // cout << "BIEN" << nodo[i];
                }
                else {
                    ret.push_back(0);
                    // cout << "MAL";
                }
            }
        }
        else {
            // cout << "APAGO " << nodo[i] << " ";
           if (nodo[i] == 0) {
                if (p_w == 1) {
                    p_w = 0;
                    ret.push_back(1);
                    // cout << "BIEN";
                }
                else {
                    ret.push_back(0);
                    // cout << "MAL";
                }
            }
            else {
                if (is_wifi[nodo[i]]) {
                    // cout << "BIEN" << is_wifi[nodo[i]];
                    sons_w--;
                    ret.push_back(1);
                    is_wifi[nodo[i]] = false;
                }
                else {
                    ret.push_back(0);
                    // cout << "MAL";
                }
            } 
        }
        // cout << endl;
        
    }
    
    return ret;
}
