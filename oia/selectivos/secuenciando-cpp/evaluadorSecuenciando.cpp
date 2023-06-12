// Include practico para compilar con geany: puede ser necesario borrarlo en otros entornos.
//#include "secuenciando.cpp"

#include <iostream>
#include <string>

using namespace std;

string secuenciar(int N, string s);

string secret;
int preguntas = 0;

int medir(string cad)
{
    preguntas++;
    int i=0;
    for (int j=0;j<int(secret.size()); j++)
    if (i < int(cad.size()) && cad[i] == secret[j])
        i++;
   // cout<<"medir: "<<cad<<" "<<i<<" "<<int(cad.size())<<" "<<(i==int(cad.size()))<<"\n";
    return i == int(cad.size());
}

int main()
{
    string s;
    getline(cin, s);
    getline(cin, secret);
    string resultado = secuenciar(int(secret.size()), s);
    
    if (resultado != secret)
    {
        cout << "Resultado erroneo: " << resultado << endl;
    }
    else
    {
        cout << "Se adivino con exito!!" << endl;
        cout << preguntas << " preguntas realizadas." << endl;
    }
    return 0;
}
