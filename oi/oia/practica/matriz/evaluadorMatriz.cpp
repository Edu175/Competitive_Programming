#include <bits/stdc++.h>

using namespace std;

void procesaMatriz(vector<vector<int> > matriz, vector<long long> &resultadoEnArreglo, vector<vector<long long> > &resultadoEnMatriz);

int main()
{
	//cout<<"evaluador\n";
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
    vector<vector<long long> > resultadoEnMatriz;
    procesaMatriz(matriz, resultadoEnArreglo,  resultadoEnMatriz);
    //cout<<"return"; return 0;
    for (int i=0;i<int(resultadoEnArreglo.size());i++)
    {
        if (i > 0) cout << " ";
        cout << resultadoEnArreglo[i];
    }
    cout << endl;
    cout << resultadoEnMatriz[0][0] << " " <<  
            resultadoEnMatriz[0][1] << " " <<  
            resultadoEnMatriz[1][0] << " " <<  
            resultadoEnMatriz[1][1] << endl;
    return 0;
}
