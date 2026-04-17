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
            } else if (x[j] > 0){
                x[j]--;
                bombones++;
            }
            j++;
        }
        if (bombones == K) {cajas++;} else {break;}
        if (cajas >= mid) {return true;}
    }
    return (cajas >= mid);
}

long long bombones(int K, vector<int> &x) {
    long long suma = 0;
    for (long long i = 0; i<x.size(); i++){
        suma += x[i];
    }

    if (K > x.size()) {return 0;}
    if (suma < K || x.size() < K) {return 0;}
    if (K == 1 && x.size() == 1) {return suma;}

    long long lo = 0, hi = suma, mid, respuesta;
    while (hi - lo > 1){
        mid = (hi + lo) / 2;
        if (simularBombones(K, x, mid)){
            //cout << "LO: " << lo << endl;
            lo = mid;
        } else{
            //cout << "HI: " << hi << endl; 
            hi = mid;
        }
    }

    //cout << endl << "POST" << endl << "HI: " << hi << endl;
    //cout << "LO: " << lo << endl << endl;

    if (suma / x[0] == x[0]) {hi--;}
    respuesta = hi;

    return respuesta;
}
