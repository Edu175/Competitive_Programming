#include <string>
#include <vector>
#include <algorithm>

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
            sort(x.begin(), x.end());
            vector<int> actual;
            for(int i = 0; i < K; i++){
                actual.push_back(x[x.size() - 1]);
                x.pop_back();
            }
            while(actual.size() == K){
                sort(actual.end(), actual.begin());
                for(int i = 0; i < K; i++){
                    if(actual[actual.size() - 1] == 0){
                        actual.pop_back();
                        if(x.size() != 0){
                            actual.push_back(x[x.size() - 1]);
                            x.pop_back();
                        }
                    }
                    actual[i]--;
                }
                cant_max++;
            }

        }
    }
    return cant_max;
}
