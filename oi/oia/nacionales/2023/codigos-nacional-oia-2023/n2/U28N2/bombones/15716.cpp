#include <vector>
#include <string>

using namespace std;

long long bombones(int K, vector<int> &x) {
    // AQUI SE DEBE IMPLEMENTAR LA SOLUCION
    int ceros = 0;
    int cont = 0;
    int auxK = K;
    bool flag = true;
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

    else if (x.size() == K) {
        while (flag == true) {
            for (int i = 0; i < K; ++i) {
                if (x[i] > 0) {
                    x[i]--;

                    cont++;
                }
                if (x[i] == 0) {
                    flag = false;
                }
            }
        
            if (cont == K) {
                cajas++;
            }
            cont = 0;
        }
    }

    if (x.size() < K) {
        cajas = 0;
    }

    else if (x.size() > K) {    
        while (ceros <= (x.size() - K)) {
            
            for (int i = 0; i < x.size(); ++i) {
                if (x[i] == 0) { 
                    i++;
                    ceros++;
                    
                    if (auxK < x.size()) {
                        auxK++;
                    }
                }
                if (x[i] > 0) {
                    x[i]--;

                    cont++;
                }
                if (cont == K) {
                    cajas++;
                    i = x.size();
                }
            }

            cont = 0;
        }

    }
    
    return cajas;
}
