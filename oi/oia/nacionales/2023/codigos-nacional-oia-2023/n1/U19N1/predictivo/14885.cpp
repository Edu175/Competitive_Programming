#include <iostream>
#include <string>
#include <vector>

using namespace std;

int predictivo(vector<string> &r1, vector<string> &r2, vector<string> &r3, string &texto){
    vector<string> textos;
    string tex;
    string s;
    int cont = 0;
    for(int i = 0; i < 6; i++){
        tex += r1[i];
        tex += " ";
        tex += r2[i];
        tex += " ";
        tex += r3[i];
        s = texto.substr(0, tex.length());
        s == tex ? cont++ : cont += 0;
        tex = "";
    }
    return cont;
}
