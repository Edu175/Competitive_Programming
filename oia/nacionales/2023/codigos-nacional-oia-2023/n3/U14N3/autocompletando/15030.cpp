#include <string>
#include <vector>

using namespace std;

int autocompletando(int K, vector<string> &r1, vector<string> &r2, vector<string> &r3, string &texto) {
    if(K>1&&K<1001){
        long ran=random();
        if((ran%2)==0){
            return 1;
        }
        else {return 0;}
    }
}
