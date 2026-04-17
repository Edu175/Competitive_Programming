#include <iostream>
#include <string>
#include <vector>

using namespace std;

int chocolates(int K, vector<int> &x){
    int n = 0, o = 0;
    for(int i = 0; i < x.size(); i++){
        n += x[i];

    }
    o = n / K;
    int cont = 0;
    for(int i = 0; i < x.size(); i++){
        if(o - x[i] >= 0){
            cont += o - x[i];
        }
    }
    cout << cont  << endl;
    if(x.size() == 1) return n;
    if(K == 1) return n;
    if(x.size()%K == 0) return K;
    if(n%K == 0) return K;
    return x.size();
}
