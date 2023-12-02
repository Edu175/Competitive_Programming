#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool estanOrdenados(vector<int> v){
    for(int i = 0; i < v.size() - 1; i++){
        if(v[i] < v[i+1]){
            return false;
        }
    }
    return true;
}

vector<int> sortInverso(vector<int> &v){
    vector<int> r;
    int temp, temp2;
    for (int i = 0; i < v.size(); i++)
        r.push_back(i);
    while(!estanOrdenados(v)){
        for(int i = 0; i < v.size() - 1; i++){
                if(v[i] < v[i+1]){
                    // Producir un sort
                    temp = v[i];
                    v[i] = v[i+1];
                    v[i+1] = temp;
                    temp2 = r[i];
                    r[i] = r[i+1];
                    r[i+1] = temp2;
                }
        }
    }
    return r;
}

void removeZero(vector<int> v1, vector<int> v2, int i){
    v1.erase(v1.begin() + i);
    v2.erase(v2.begin() + i);
}

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
        vector<int> indices = sortInverso(x);
        while(indices.size() > K){
            if (K >= x.size()){
                r++;
                for(int i = 0; i < K; i++){
                    x[i]--;
                    if(x[i] == 0)
                        removeZero(x, indices, i);
                }
            }
            else{
                break;
            }
        }
    }
    return r;
}
