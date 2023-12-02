#include <string>
#include <vector>

using namespace std;

long long bombones(int K, vector<int> &x) {
    long long cant_max = 0;
    if(K == 1)
        for(int i : x)
            cant_max += i;
    else{
        int same = 1;
        for(int i = 0; i < x.size(); i++)
            if(x[i] == x[i + 1])
                same++;
        if(same == x.size())
            return x.size() / K;
        else{
            vector<bool> deleted(x.size(), false);
            int cant_tipos = x.size();
            while(cant_tipos <= K){
                int bombones_usados = 0;
                for(int i = 0; i < x.size(); i++){
                    if(x[i] == 0)
                        if(!deleted[i]){
                            cant_tipos--;
                            deleted[i] = true;
                        }
                    else if(bombones_usados != K){
                            x[i]--;
                            bombones_usados++;
                    }else{
                        cant_max++;
                        break;
                    }
                }
            }
        }
    }
    return cant_max;
}
