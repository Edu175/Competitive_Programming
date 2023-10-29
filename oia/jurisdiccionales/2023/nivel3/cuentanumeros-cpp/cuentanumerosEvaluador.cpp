#include <iostream>
#include <string>
#include <vector>

using namespace std;

void inicializar();
void nuevoNumero(int x);
int contar(int a, int b);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    inicializar();
    for (int i=1; i<=N;i++) {
        int qt;
        cin >> qt;
        if (qt == 0)
        {
            int a,b;
            cin >> a >> b;
            cout << contar(a,b) << "\n";
        }
        else
        {
            int x;
            cin >> x;
            nuevoNumero(x);
        }
    }
    return 0;
}
