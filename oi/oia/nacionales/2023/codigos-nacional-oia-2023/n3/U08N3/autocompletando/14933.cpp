#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

vector<string>cad;

int autocompletando(int K, vector<string> &r1, vector<string> &r2, vector<string> &r3, string &texto) {
    for(int i=0;i<r1.size();i++){
        auto band=find(texto.begin(),texto.end(),r1[i][0]);
        for(int j=1;j<r1[i].size();j++){
            band=find(texto.begin(),texto.end(),r1[i][j]);
            if(band==texto.end()) break;
        }
        if (band==texto.end()) continue;
        for(int j=1;j<r2[i].size();j++){
            band=find(texto.begin(),texto.end(),r2[i][j]);
            if(band==texto.end()) break;
        }
        if(band==texto.end()) continue;
        for(int j=1;j<r3[i].size();j++){
            band=find(texto.begin(),texto.end(),r3[i][j]);
            if(band==texto.end()) break;
        }
        if(band!=texto.end()) return 1;
    }
    return 0;
}
