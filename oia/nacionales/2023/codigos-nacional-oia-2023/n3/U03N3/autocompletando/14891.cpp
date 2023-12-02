#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;

int autocompletando(int K, vector<string> &r1, vector<string> &r2, vector<string> &r3, string &texto){
    map< string, string > m;
    vector < string > seg;
    for(int i=0; i<r1.size(); i++){
        string cad= r1[i] + ' ' +r2[i]; 
        m.insert({cad, r3[i]});
    }
    string palabra;
    int cont=0;
    for(int i=0; cont < K ; i++){
        palabra += texto[i];
        if(texto[i] == ' '){
            seg.push_back(palabra.substr(0,palabra.size()-1));
            palabra.clear();
            cont++;
        }
    }
    vector <string > pred;
    for(int i=0; i<seg.size()-1; i++){
        pred.push_back(seg[i]+ ' ' +seg[i+1]);

        if(m.count(pred[i]) < 1) return 0  ;
    }
    return 1;
    
}
