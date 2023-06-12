// Include practico para compilar con geany: puede ser necesario borrarlo en otros entornos.
//#include "gps.cpp"

#include <iostream>
#include <vector>

using namespace std;

vector<long long> gps(int N, int M, int comienzo, int fin, int K, vector<int> origen, vector<int> destino, vector<int> tiempo);

int main()
{
    int N,M;
    cin >> N >> M;
    int comienzo, fin;
    cin >> comienzo >> fin;
    int K;
    cin >> K;
    vector<int> origen(M), destino(M), tiempo(M);
    for(int i=0; i<M; i++)
        cin >> origen[i] >> destino[i] >> tiempo[i];
    vector<long long> result = gps(N,M,comienzo,fin,K,origen, destino, tiempo);
    for (int i=0; i<int(result.size()); i++)
    {
        if (i > 0)
            cout << " ";
        cout << result[i];
    }
    cout << "\n";
    return 0;
}
