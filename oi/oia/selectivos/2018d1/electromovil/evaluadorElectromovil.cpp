// Include practico para compilar con geany: puede ser necesario borrarlo en otros entornos.
//#include "electromovil.cpp"

#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> electromovil(int E, vector<int> ubicacion, vector<int> autonomia);

int main()
{
    int E;
    cin >> E;
    vector<int> ubicacion(E), autonomia(E);
    for(int i=0; i<E; i++)
        cin >> ubicacion[i] >> autonomia[i];
    vector<int> result = electromovil(E,ubicacion, autonomia);
    cout << result.size() << "\n";
    for (int i=0; i<int(result.size()); i++)
        cout << result[i] << "\n";
    return 0;
}
