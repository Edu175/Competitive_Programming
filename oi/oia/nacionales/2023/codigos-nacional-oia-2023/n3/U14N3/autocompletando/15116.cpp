#include <string>
#include <vector>

using namespace std;

int autocompletando(int K, vector<string> &r1, vector<string> &r2, vector<string> &r3, string &texto) {
    string textovec={texto};
    int siono=0;
    int cantidad=r1.size();
    if (((K<1000001)&&(K>1))&&((cantidad<1001)&&(cantidad<1001))){
        if (cantidad==K){
            return 0;
        }
        for(int i=0;i<cantidad;i++){
            if((texto[i]==r1[1])&&(texto[i+1]==r2[2])&&(texto[i+2]==r2[2])){
                siono=1;
            }
        }
        if(siono>0){
            return 1;
        }
        else{
            return 0;
        }
    }
    else{}
}

