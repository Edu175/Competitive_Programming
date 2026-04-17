#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long sumar(vector<int> v){
    long long suma = 0;
    for(int n:v)
        suma += n;
    return suma;
}

bool todosValoresUno(vector<int> v){
    for(int n:v){
        if (n != 1)
            return false;
    }
    return true;
}

long long bombones(int K, vector<int> &x) {
    // AQUI SE DEBE IMPLEMENTAR LA SOLUCION
    long long r = 0;
    int aBajar;
    if(x.size() == 1){
        r = x[0];
    }
    else if (K == 1){
        r = sumar(x);
    }
    else if(todosValoresUno(x)){
        r = sumar(x) / K;
    }
    else{
        vector<int> indicesCon0;
        while(x.size() >= K){
            sort(x.begin(), x.end());
            reverse(x.begin(), x.end());
            aBajar = x[K-1];
            if (x.size() > K)
                aBajar -= x[K];
            r += aBajar;
            for(int i = 0; i < K; i++){
                x[i] -= aBajar;
                if(x[i] == 0)
                    indicesCon0.push_back(i);
            }
            sort(indicesCon0.begin(), indicesCon0.end());
            reverse(indicesCon0.begin(), indicesCon0.end());
            for(int algo: indicesCon0){
                x.erase(x.begin() + algo);
            }
            indicesCon0.clear();
        }
    }
    return r;
}
