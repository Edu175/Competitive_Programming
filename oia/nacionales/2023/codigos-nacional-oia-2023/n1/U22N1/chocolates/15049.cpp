#include <iostream>
#include <string>
#include <vector>

using namespace std;

int chocolates(int K, vector<int> &x) {
    int menor = 0;
    for(int i = 0; i < x.size(); i++){
        if(menor > x[i]){
            menor = x[i];
        }
    }

    return menor;
}
