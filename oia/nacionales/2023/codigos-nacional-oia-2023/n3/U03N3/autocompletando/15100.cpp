#include <bits/stdc++.h>

using namespace std;

int autocompletando(int K, vector<string> &r1, vector<string> &r2, vector<string> &r3, string &texto){
    map< string, string > m;
    vector < string > seg;
    for(int i=0; i<r1.size(); i++){
        string cad= r1[i] + ' ' +r2[i]; 
        m.insert({cad, r3[i]});
    }
    string palabra;
    for(int i=0; i < texto.size() ; i++){
        palabra += texto[i];
        if(texto[i] == ' '){
            seg.push_back(palabra.substr(0,palabra.size()-1));
            palabra.clear();
        }
    }
    vector <string > pred;
    K=K-2;
    for(int i=0; i<seg.size()-1; i++){
        pred.push_back(seg[i]+ ' ' +seg[i+1]);

        auto search=m.find(pred[i]);
        if(search == m.end()){
            K--;
            continue;
        }
        if(search->second != seg[i+2]) K--;
    }
    if(K>=0) return 1;
    else return 0;
    
}
