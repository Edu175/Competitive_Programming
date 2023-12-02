#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>


using namespace std;

int autocompletando(int K, vector<string> &r1, vector<string> &r2, vector<string> &r3, string &texto) {
    int res = 0;
    int mod = 2;
    vector<string> palabras;
    string nuevostr;
    for (int i = 0; i < texto.size(); i++){
        if (texto[i] != (char)32){
            nuevostr.push_back(texto[i]);
        }
        else{
            palabras.push_back(nuevostr);
            nuevostr = "";
        }
    }
    palabras.push_back(nuevostr);
    for (int p = 2; p < palabras.size(); p++){
        bool found = false;
        for (int i = 0; i < r1.size(); i++){
            if (r1[i] == palabras[p-2]){
                if (r2[i] == palabras[p-1] && r3[i] == palabras[p]){
                    found = true;
                }
            }
        }
        if (!found){
            mod++;
        }
    }
    if (mod <= K){
        res = 1;
    }
    
    // AQUI SE DEBE IMPLEMENTAR LA SOLUCION
    return res;
}
