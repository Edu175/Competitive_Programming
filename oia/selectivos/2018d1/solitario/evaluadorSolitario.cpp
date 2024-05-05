// Include practico para compilar con geany: puede ser necesario borrarlo en otros entornos.
//#include "solitario.cpp"

#include <iostream>
#include <vector>

using namespace std;

int solitario(vector<int> c, long long N, int K);

using namespace std;

int main()
{
    int M,K; long long N;
    cin >> M >> K >> N;
    vector<int> c(M);
    for (int i=0;i<M;i++)
        cin >> c[i];
    int result = solitario(c, N, K);
    cout << result << endl;
    return 0;
}
