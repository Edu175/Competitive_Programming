#include <bits/stdc++.h>
using namespace std;
long long rta;
void rango(int i, int j, vector<int>&x){
    long long menor = x[i];
    rta = menor;
    //cout << "rango: " << i << " " << j << endl;
    for(int h=i; h<=j; h++){
        x[h] = x[h] - menor;
    //    cout << x[h] << " ";
    }
    //cout << endl;
}

//void mostrar(vector<int>x){
//    for(auto &it:x) cout << it << " ";
    //cout << endl;
//}

long long bombones(int K, vector<int> &x){
    long long cont = 0;

    if(K == 1){
        for(auto &it:x) cont += it;
        return cont;
    }
    sort(x.begin(), x.end());
        while(x[x.size()-K] > 0){
          //  mostrar(x);
        rango((x.size()-K), x.size()-1, x);
        sort(x.begin(), x.end());
        cont += rta;
    }
    return cont;
}
