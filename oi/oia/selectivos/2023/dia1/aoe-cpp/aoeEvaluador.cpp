#include <iostream>
#include <string>
#include <vector>
#include <cassert>

using namespace std;

void inicializar(int N);
vector<int> tiempo(int t);
vector<int> jugador(int e);

int main() {
    int N;
    cin >> N;
    inicializar(N);
    for (int queries=0;queries<N;queries++) {
        int b,x;
        cin >> b >> x;
        vector<int> returned;
        if (b == 1)
            returned = tiempo(x);
        else if (b == 2)
            returned = jugador(x);
        else
            assert(false);
        cout << int(returned.size());
        for (int i=0;i<int(returned.size()); i++)
            cout << " " << returned[i];
        cout << endl;
    }
    return 0;
}
