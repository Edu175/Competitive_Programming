// La siguiente linea es lo mas comodo para trabajar localmente con GEANY, el editor recomendado en la OIA.
// Al usar geany, basta utilizar F9 (construir) sobre este archivo evaluadorMatriz.cpp para compilar todo el programa.
// Con otros editores, o si se compila manualmente, puede ser necesario o conveniente borrar la linea siguiente. 
#include "matriz.cpp"

// De manera similar, puede ser necesario descomentar la definicion de este struct si no se trabaja con geany de la manera indicada.

//struct Resultado
//{
//    long long suma, producto, maximo, minimo;
//};


#include <vector>
#include <iostream>

using namespace std;

void procesaMatriz(vector<vector<int> > matriz, vector<long long> &resultadoEnArreglo, Resultado &resultadoEnRegistro);

int main()
{
    int n,m;
    cin >> n >> m;
    vector<vector<int> > matriz;
    matriz.resize(n);
    for (int i=0;i<n;i++)
    {
        matriz[i].resize(m);
        for (int j=0;j<m;j++)
            cin >> matriz[i][j];
    }
    vector<long long> resultadoEnArreglo;
    Resultado resultadoEnRegistro;
    procesaMatriz(matriz, resultadoEnArreglo,  resultadoEnRegistro);
    for (int i=0;i<int(resultadoEnArreglo.size());i++)
    {
        if (i > 0) cout << " ";
        cout << resultadoEnArreglo[i];
    }
    cout << endl;
    cout << resultadoEnRegistro.suma     << " " <<  
            resultadoEnRegistro.producto << " " <<  
            resultadoEnRegistro.maximo   << " " <<  
            resultadoEnRegistro.minimo   << endl;
    return 0;
}
