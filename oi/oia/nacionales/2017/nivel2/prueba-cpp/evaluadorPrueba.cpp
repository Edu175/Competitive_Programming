// La siguiente linea se usa para compilar en Geany con F9. Compilando de otra forma, podria ser necesario quitarla.
//#include "prueba.cpp"

#include <iostream>
#include <string>

using namespace std;

int  prueba( string palabra );

int main()
{
    string s; cin >> s;
    cout << prueba(s) << endl;
    return 0;
}
