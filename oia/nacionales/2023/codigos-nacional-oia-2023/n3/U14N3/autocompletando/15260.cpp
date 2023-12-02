#include <string>
#include <vector>

using namespace std;

int autocompletando(int K, vector<string> &r1, vector<string> &r2, vector<string> &r3, string &texto) {
    string textoa={texto};
    int siono=0;
    int cantidad=r1.size();
    if (((K<1000001)&&(K>1))&&((cantidad<1001)&&(cantidad>2))){
        if (cantidad==K){
            return 0;
        }
        for(int i=0;i<cantidad;i++){
        for (int j = 0; j < cantidad; i++){
            if((texto[i].compare(r1[j])==true)&&(texto[i+1].compare.(r2[j])==true)&&(texto[i+2],r3[j])){
            siono=1;
        }
        }
        }
    if(siono>0){
        return 1;
    }
    if (siono<1){
        return 0;
    }
    }
}

