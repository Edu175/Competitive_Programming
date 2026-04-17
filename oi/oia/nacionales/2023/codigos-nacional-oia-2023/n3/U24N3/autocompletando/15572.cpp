#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
vector <string> palabras;
string guardar = "";
int EsIgual(int K,vector<string> &pal,vector<string> &r1, vector<string> &r2, vector<string> &r3){
int a= 0;
for(int i=0; i<r1.size(); i++){
    for(int j=0; j<K; j++){
       if(pal[0]==r1[i]&pal[1]==r2[i]&pal[2]==r3[i]){
                a=1;
        }
    }
}
return a;
}

int autocompletando(int K, vector<string> &r1, vector<string> &r2, vector<string> &r3, string &texto) {
    // AQUI SE DEBE IMPLEMENTAR LA SOLUCION
    texto[texto.size()]=' ';
    for(int i = 0; i<=texto.size(); i++)
    {
        if(texto[i]==' ')
        {
            palabras.push_back(guardar);
            guardar = "";
        }else{
            guardar = guardar+texto[i];
        }

    }
    return EsIgual(K,palabras,r1,r2,r3);
}
