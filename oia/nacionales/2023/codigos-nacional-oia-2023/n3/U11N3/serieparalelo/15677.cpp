#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int serieparalelo(vector<int> &t, vector<int> &e) {
    // AQUI SE DEBE IMPLEMENTAR LA SOLUCION
    if (t.size() == 1) {
        return 1;
    }
    else {
        if (t[0] == t[1]) {
            if (t[0] == 1) return 1;
            else {
                if (e[1] == 1) return 2;
                else return 1;
            } 
        }
        else if (t[0] == 1) return 1;
        else {
            if (e[1] == 1) return 2;
            else return 1;
        }
    }
}
