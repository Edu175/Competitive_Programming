#include <iostream>
#include <string>
#include <vector>

using namespace std;

long long agregar(long long x);
long long sacar(long long x);

int main() {
    int Q;
    cin >> Q;
    for (int i = 0; i < Q; i++) {
        string t; long long x;
        cin >> t >> x;
        if (t == "s")
            cout << sacar(x) << endl;
        else if (t == "a")
            cout << agregar(x) << endl;
        else
        {
            cout << "OPERACION INVALIDA! No es ni s ni a" << endl;
            return 0;
        }
    }
    return 0;
}
