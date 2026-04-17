#include <bits/stdc++.h>

using namespace std;

bool simularBombones(long long n){
    /*for(long long i = 0; i<n; i++){

    }*/
    return true;
}

long long bombones(int K, vector<int> &x) {
    long long suma = 0;
    for (long long i = 0; i<x.size(); i++){
        suma += x[i];
    }

    long long lo = -1, hi = suma, mid, respuesta;
    while (hi - lo > 1){
        mid = (hi - lo) / 2;
        if (simularBombones(mid)){
            lo = mid;
        } else{
            hi = mid;
        }
    }
    respuesta = hi;
    return respuesta;
}
