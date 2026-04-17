#include <string>
#include <vector>

using namespace std;

long long bombones(int K, vector<int> &x) {
    long long cant_max = 0;
    if(K == 1)
        for(int i : x)
            cant_max += i;
    else{
        int rep = 0;
        for(int i = 0; i < x.size(); i++){
            if(x[i] == 1){
                rep += 1;
            }
        }
        if(rep == x.size())
            return 1;
    }
    return cant_max;
}
