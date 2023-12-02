#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int p_w = 0;
int sons_w = 0;
vector<bool> is_wifi;
vector<vector<int>> hijos;
vector<int> ret;

bool look_up(int x, vector<int>& padre) {
    bool posible = true;
    // cout << " p " << x << endl;
    while (x != 0) {
        x = padre[x-1];
        // cout << "x  " << x << endl;
        if (is_wifi[x]) posible = false;
    }
    return posible;
}

bool look_down (int x) {
    bool possible = true;
    // cout << " - " << x << endl;
    if (is_wifi[x]) return false;
    for (auto hijo : hijos[x]) {
        possible = look_down(hijo);
        if (!possible) return false;
    }
    return true;
}

vector<int> hoteles(vector<int>& padre, vector<int>& tipo, vector<int>& nodo) {
    // AQUI SE DEBE IMPLEMENTAR LA SOLUCION
    is_wifi.resize(padre.size()+1, false);
    hijos.resize(padre.size()+1);
    for (int i = 0; i < padre.size(); i++) {
        hijos[padre[i]].push_back(i+1);
    }   
    // for (int i = 0; i < hijos.size(); i++) {
    //     cout << i << " ";
    //     for (auto hijo : hijos[i]) cout << hijo << " ";
    //     cout << endl;
    // }
    bool posible = true;

    for (int i = 0; i < tipo.size(); i++) {
        // cout << endl << endl << i << " / " << tipo[i] << " - " << nodo[i] << endl;;
        if (tipo[i] == 0) {
            if (is_wifi[nodo[i]]) ret.push_back(0);
            else {
                // cout << 1 << endl;
                posible = look_up(nodo[i], padre);
                if (!posible) ret.push_back(0);
                else {
                    // cout << 3 << endl;
                    posible = look_down(nodo[i]);
                    if (!posible) ret.push_back(0);
                    else {
                        ret.push_back(1);
                        is_wifi[nodo[i]] = true;
                    }
                }
            }
        }
        else {
            if (!is_wifi[nodo[i]]) ret.push_back(0);
            else {
                ret.push_back(1);
                is_wifi[nodo[i]];
            }
        }
    }
    
    return ret;
}
