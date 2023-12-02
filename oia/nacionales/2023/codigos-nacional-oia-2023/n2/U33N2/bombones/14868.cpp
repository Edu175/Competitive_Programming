#include <string>
#include <vector>

using namespace std;

long long bombones(int K, vector<int> &x) {
    long long cant_max = 0;
    if(K == 1)
        for(int i : x)
            cant_max += i;
    else{
        int cant_tipos = x.size();
        int start = 0;
        vector<bool> deleted(x.size(), false);
        while(cant_tipos < K){
            int bombones_usados = 0;
            for(int i = start; i < x.size(); i++){
                if(x[i] != 0 && bombones_usados != K){
                    x[i]--;
                    bombones_usados++;
                }else if(deleted[i] == false){
                    start++;
                    cant_tipos--;
                    deleted[i] = true;
                }
            }
            cant_max += 1;
        }
    }
    return cant_max;
}
