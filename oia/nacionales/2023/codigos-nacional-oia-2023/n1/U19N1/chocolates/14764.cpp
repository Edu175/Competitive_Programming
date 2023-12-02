#include <iostream>
#include <string>
#include <vector>

using namespace std;

int chocolates(int K, vector<int> &x){
    int n = 0;
    for(int i = 0; i < x.size(); i++){
        n += x[i] / K;
    }

    return n;
}
