#include <string>
#include <vector>
#include <iostream>
using namespace std;

int predictivo(vector<string> &r1, vector<string> &r2, vector<string> &r3, string &texto) {
    texto += " ";
    vector<string> textoV;
    string cadena;

    for(auto c : texto){
        if(c != ' ') cadena += c;
        else{
            textoV.push_back(cadena);
            cadena = "";
        }
    }

    int er = 0;
    for(int i = 0; i < textoV.size()-2; i++){
        bool encontrada = false;
        for(int j = 0; j < r1.size(); j++){
            if(r1[j] == textoV[i] && r2[j] == textoV[i+1]){
                if(r3[j] != textoV[i+2]){
                    er++;
                    if(er == 2) return 0;
                }
                else{
                    encontrada = true;
                    break;
                };
            }
        }
        if(!encontrada){
            er++;
            if(er == 2) return 0;
        }
    }
    return 1;
}


