#include <iostream>
#include <string>
#include <vector>

using namespace std;

int chocolates(int K, vector<int> &x){
    int n = 0, o = 0;
    for(int i = 0; i < x.size(); i++){
        n += x[i];

    }
    //cout << ":" << K << endl << n%x.size()<< endl;
    if(n%x.size() == 0 && n != 1 && K != 1){
        return x.size();
    }
    o = n / K;
    int cont = 0;
    for(int i = 0; i < x.size(); i++){
        if(o - x[i] >= 0){
            cont += o - x[i];
        }
    }
    return n%K == 0 ? n : cont;
}
