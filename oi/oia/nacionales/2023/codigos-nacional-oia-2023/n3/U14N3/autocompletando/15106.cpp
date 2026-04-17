#include <string>
#include <vector>

using namespace std;

int autocompletando(int K, vector<string> &r1, vector<string> &r2, vector<string> &r3, string &texto) {
    
    int cantidad=r1.size();
    if (((K<1000001)&&(K>1))&&((cantidad<1001)&&(cantidad<1001))){
        long ran=random();
        if((ran%2)==0){
            return 1;
        }
        else {return 0;}
    }
}
