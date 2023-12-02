#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

vector<vector<char>>a;
map<pair<vector<char>,vector<char>>,string>m;

int autocompletando(int K, vector<string> &r1, vector<string> &r2, vector<string> &r3, string &texto) {
    bool band=false;
    auto x=find(texto.begin(),texto.end(),r1[0][0]);
    if(x!=texto.end()) x=find(texto.begin(),texto.end(),r2[0][0]);
    if(x!=texto.end()) band=true;
    if(band) return 1;
    return 0;
}


/*a.resize(texto.size());
    int aux=0,j=-1;
    char a=r1[0],b=r2[0],c=r3[0];


    for(int i=0;i<texto.size() && j<texto.size();i++){
        j++;
        for(int p=0;texto[j]!=' ';p++){
            a[i][p]=texto[j];
            j++;
        }
        aux=i;
    }
    a.resize(aux+1);

    for(int i=0;r1[i].size();i++){
        bool band=true;
        for(int j=0;j<r1[i].size();j++){
            if(a[aux][j]!=r1[i][j]){
                band=false;
                break;
            }
            if(band){
                if(a[aux][j]!=r2[i][j]){
                    band=false;
                    break;
                }
            }
        }
    }

    if(m[p].size()!=0) return 1;
    else return 0;*/
