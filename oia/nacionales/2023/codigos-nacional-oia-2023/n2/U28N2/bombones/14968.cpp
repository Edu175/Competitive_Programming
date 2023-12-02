#include <string>
#include <vector>

using namespace std;

long long bombones(int K, vector<int> &x) {
    // AQUI SE DEBE IMPLEMENTAR LA SOLUCION
    int cont = 0;
    int aux = 0;
    int auxK = K;
    long long cajas = 0;

    while (aux <= (x.size() - K)) {
        cout<<"Mientras que aux sea menor que la diferencia entre size de x y K"<<endl;
        
        for (int i = 0; i < auxK; ++i) {
            if (x[i] == 0) { 
                aux++;
                i++;

                if (auxK < x.size()) {
                    auxK++;
                }
                cout<<"Pregunta si K < size de x"<<endl;
            }
            if (x[i] > 0) {
                x[i]--;

                cont++;

                cout<<"Pregunta si x[i] > 0: "<<i<<endl;
            } 
        }

        if (cont == K) {
            cajas++;

                cout<<"Pregunta si cont es igual a K"<<endl;
        }

        cont = 0;
    }

    return cajas+1;
}
