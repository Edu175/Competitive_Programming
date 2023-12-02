#include <bits/stdc++.h>
using namespace std;

int predictivo(vector<string> &r1, vector<string> &r2, vector<string> &r3, string &texto){
    string tex;
    string s, a, b;
    int cont = 0;
    for(int i = 0; i < r1.size(); i++){
        tex += r1[i];
        tex += " ";
        tex += r2[i];
        tex += " ";
        tex += r3[i];
        s = texto.substr(0, tex.size());
        a = string(s);
        b = string(tex);
        //cout << ":" << a << ":/n:" << b << ":/n";
        tex = "";
        if(a == b){
            cont++;
        }
    }
    return cont;
}
