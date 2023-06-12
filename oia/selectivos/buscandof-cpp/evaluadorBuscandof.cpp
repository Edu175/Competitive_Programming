// Include practico para compilar con geany: puede ser necesario borrarlo en otros entornos.
//#include "buscandof.cpp"

#include <iostream>
#include <vector>

using namespace std;

int buscandof(int N, vector<int> x, vector<int> y);

int main()
{
    int N;
    cin >> N;
    vector<int> x(N), y(N);
    for(int i=0; i<N; i++)
        cin >> x[i] >> y[i];
    cout << buscandof(N,x,y) << endl;
    return 0;
}
