#include <bits/stdc++.h>

using namespace std;

int autocompletando(int K, vector<string> &r1, vector<string> &r2, vector<string> &r3, string &texto)
{
    //cout << texto << endl <<endl;
    vector <string> arrayTexto;
    int x=0;
    string palabra="", siguiente="";
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
    cout << r1.size() << endl;
    while(found==0 && x<r1.size())
    {

        /*cout << "r1[" <<x<<"] = "<< r1[x]<<endl;
        cout << "arrayTexto["<< arrayTexto.size()-2 <<"] = "<< arrayTexto[arrayTexto.size()-2]<<endl;
        cout << "r2[" <<x<<"] = "<< r2[x]<<endl;
        cout << "arrayTexto["<< arrayTexto.size()-1 <<"] = "<< arrayTexto[arrayTexto.size()-1]<<endl;*/
        if(arrayTexto[arrayTexto.size()-2]==r1[x] && arrayTexto[arrayTexto.size()-1]==r2[x])
            found=1;
        //cout << "found: " <<found <<endl << endl;
        x++;
    }
    //for(int i=0; i<arrayTexto.size(); i++) cout<<arrayTexto[i]<<endl;
    return found;
}
