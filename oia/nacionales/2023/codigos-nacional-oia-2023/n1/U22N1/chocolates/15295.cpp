#include <iostream>
#include <string>
#include <vector>

using namespace std;

int chocolates(int K, vector<int> &x) {
    int contador = 0;
    while(x.size() >= K){
        for(int i = 0; i < K; i++){
            if(x[i] == 0){
                x[i] = x[x.size()-1];
                x.pop_back();
            }else if(x[i] != 0){
                x[i] -= 1;
            }

        }
        contador += 1;
    }
    return contador-2;
}
int main(){
    vector<int> cantidad(3);
    int K;
    for(int i = 0; i < cantidad.size(); i++){
        cin>>cantidad[i];
    }
    cin>>K;

    int res = chocolates(K, cantidad);
    cout<<res;

}
