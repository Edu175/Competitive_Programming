#include <iostream>
#include <vector>
#include <string>

using namespace std;

void duplilong(vector<string> &palabras, int K, vector<int> & longitudes);

template <typename T>
void mostrar(const vector<T>&v)
{
    for (int i=0;i<int(v.size()); i++)
    {
        if (i > 0)
            cout << " ";
        cout << v[i];
    }
    cout << endl;
}

int main()
{
    int N,K; cin >> N >> K;
    vector<string> palabras(N);
    for (int i=0;i<N;i++)
        cin >> palabras[i];
    vector<int> longitudes(K);
    duplilong(palabras, K, longitudes);
    mostrar(palabras);
    mostrar(longitudes);
    return 0;
}
