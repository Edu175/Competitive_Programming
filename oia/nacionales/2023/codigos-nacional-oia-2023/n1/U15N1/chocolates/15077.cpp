#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int chocolates(int K, vector<int> &x) {
    long long total = 0,r = 0;
    sort(x.begin(),x.end());
    while(true){
        r = 0;
        for(int i = x.size()-1; i >= 0; i--){
            if(x[i] != 0){
                x[i]--;
                r++;
                if(r == K){
                    total++;
                    break;
                }
            }
        }
        if(r < K)return total;
    }

}

