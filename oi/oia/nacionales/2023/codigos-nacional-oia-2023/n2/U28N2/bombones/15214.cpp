#include <vector>
#include <string>

using namespace std;

long long bombones(int K, vector<int> &x) {
    // AQUI SE DEBE IMPLEMENTAR LA SOLUCION
    int cont = 0;
    int aux = 0;
    int auxK = K;
    long long cajas = 0;
    int veces=0;

    if(x.size() == 1) {
        cajas = x[0] / K;
    }

    else {    
        while (aux <= (x.size() - K)) {
            for (int i = 0; i < auxK; ++i) {
                if (x[i] == 0) { 
                    aux++;
                    i++;

                    if (auxK < x.size()) {
                        auxK++;
                    }
                }
                if (x[i] > 0) {
                    x[i]--;

                    cont++;
                } 

                if (auxK > x.size()) {
                    auxK == x.size();
                }
            }

            if (cont == K) {
                cajas++;
            }

            cont = 0;
            veces++;
            cout<<"Veces del while: "<<veces<<endl;
        }
    }


    return cajas;
}
