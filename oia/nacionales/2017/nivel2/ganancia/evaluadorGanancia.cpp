// La siguiente linea se usa para compilar en Geany con F9. Compilando de otra forma, podria ser necesario quitarla.
//#include "ganancia.cpp"

#include <bits/stdc++.h>
#include <vector>

using namespace std;

// Para compilar en Geany, no se utiliza el siguiente fragmento con el struct. Compilando de otras maneras, podria ser necesario tenerlo.

// *********** IMPORTANTE!!!!!! ********************
// NO MODIFICAR DE NINGUNA MANERA ESTE STRUCT!!!!!**
struct PQ{ int precio, cantidad; } ; //  ***********
// *************************************************
// *************************************************



int ganancia( int P, vector< PQ > fabricantes, vector< PQ > compradores, int & Fab, int & Comp );

int main()
{
    int P, F, C;
    cin >> P >> F >> C;
    vector<PQ> fab, comp;
    fab.resize(F);
    for (int i=0;i<F;i++)
        cin >> fab[i].precio >> fab[i].cantidad;
    comp.resize(C);
    for (int i=0;i<C;i++)
        cin >> comp[i].precio >> comp[i].cantidad;
    int Fab, Comp;
    int utilidad = ganancia(P, fab, comp, Fab, Comp);
    cout <</* Fab << " " << Comp << " " <<*/ utilidad << endl;
    return 0;
}
