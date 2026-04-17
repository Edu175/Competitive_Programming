#include <bits/stdc++.h>

using namespace std;

bool simularBombones(int K, vector<int> x, long long mid){
    long long cajas = 0;
    for(long long i = 0; i<mid; i++){
        long long bombones = 0;
        long long j = 0;
        while (bombones < K){
            if (j >= x.size()){
                break;
            }
            if (x[j] > 0){
                x[j]--;
                bombones++;
            }
            j++;
        }
        if (bombones == K) {cajas++;}
    }
    return (cajas >= mid);
}

long long bombones(int K, vector<int> &x) {
    long long suma = 0;
    for (long long i = 0; i<x.size(); i++){
        suma += x[i];
    }

    long long lo = 0, hi = suma, mid, respuesta;
    while (hi - lo > 1){
        mid = (hi + lo) / 2;
        if (simularBombones(K, x, mid)){
            lo = mid;
        } else{
            hi = mid;
        }
    }

    /*cout << "HI: " << hi << endl;
    cout << "LO: " << lo << endl;*/

    respuesta = hi;

    return respuesta;
}
