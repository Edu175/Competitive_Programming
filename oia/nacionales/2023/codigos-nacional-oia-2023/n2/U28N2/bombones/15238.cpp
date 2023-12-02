#include <vector>
#include <string>

using namespace std;

long long bombones(int K, vector<int> &x) {
    // AQUI SE DEBE IMPLEMENTAR LA SOLUCION
    int cont = 0;
    int aux = 0;
    int auxK = K;
    long long sum = 0;
    long long cajas = 0;

    for (int i = 0; i < x.size(); ++i) {
        sum += x[i];
    }

    if (sum == x.size()) {
        cajas = sum / K;
    }

    else if(x.size() == 1) {
        cajas = x[0] / K;
    }

    else if (K == 1) {

        cajas = sum;
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
        }
    }


    return cajas;
}
