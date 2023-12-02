#include <bits/stdc++.h>

using namespace std;
bool iguales(vector<char> a, string b)
{
    for(int i=0; i<b.size();i++)
        if(b[i]!=a[i])
            return false;
    return true;
}

int autocompletando(int K, vector<string> &r1, vector<string> &r2, vector<string> &r3, string &texto)
{
    vector <string> arrayTexto;
    vector <char> siguiente;
    int x=0;
    string palabra="";
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
    while(texto[x]!=' ')
    {
        siguiente.push_back(texto[x]);
        x++;
    }

    int found=0; x=0;
    while(found==0 && x<r1.size())
    {
        if(arrayTexto[arrayTexto.size()-2]==r1[x] && arrayTexto[arrayTexto.size()-1]==r2[x] && iguales(siguiente, r3[x]))
            found=1;
        x++;
    }
    return found;
}
