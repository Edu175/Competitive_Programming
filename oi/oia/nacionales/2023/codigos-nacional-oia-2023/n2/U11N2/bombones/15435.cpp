#include <string>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long bombones(int K, vector<int> &x) {
long long X=0;
    int size= x.size();
    int sizec=size;

    int cajas=0;
    vector<int> caja;

    vector<int> copia=x;
    int u=-1;

    for (int i=0 ; i<size ; i++){
            caja[i]=0;
        sort (copia.begin(), copia.end());
        while (caja[i]<K){
        u++;
            if (copia[sizec] == x[u]){
                x[u]-- ; caja[i]++;
        sort (copia.begin(), copia.end());
            }
        }
        cajas++;
    }

X=cajas;
return X;

  }
        X+= x[i];

    }
return X;
}
