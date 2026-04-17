#include <string>
#include <vector>
#include <iostream>

using namespace std;

int chocolates(int K, vector<int> &x) {
    int total = 0,r =0;
    while(true){
        r = 0;
        for(int i = 0; i < x.size(); i++){
            if(x[i] != 0){
                x[i]--;
                r++;
                if( r == K){
                    total++;
                    break;
                }
            }
        }
        if(r < K)return total;
    }

}

