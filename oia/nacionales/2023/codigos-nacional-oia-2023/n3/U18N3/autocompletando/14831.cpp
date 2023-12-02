#include <bits/stdc++.h>

using namespace std;

int autocompletando(int K, vector<string> &r1, vector<string> &r2, vector<string> &r3, string &texto)
{
    vector <string> arrayTexto;
    int x=0;
    string palabra;
    while(int(arrayTexto.size())<K)
    {
        if(texto[x]!=' ')
        {
            palabra=palabra+texto[x];
        }
        else
        {
            arrayTexto.push_back(palabra);
            palabra="";
        }
        x++;
    }
    int found=0; x=0;
    while(!found && x<r1.size())
    {
        if(arrayTexto[arrayTexto.size()-2]==r1[x] && arrayTexto[arrayTexto.size()-1]==r2[x])
            found=1;
        x++;
    }
    return found;
}
