// La siguiente linea se usa para compilar en Geany con F9. Compilando de otra forma, podria ser necesario quitarla.
//#include "sendero_old2.cpp"

#include <bits/stdc++.h>

using namespace std;

int sendero(int B, int G, int N, string &baldosas);

int main()
{
    int a,b,c;
    cin >> a >> b >> c;
    string baldosas;
    cin >> baldosas;
    int val = sendero(a,b,c,baldosas);
    cout << baldosas << endl;
    cout << val << endl;
    return 0;
}
