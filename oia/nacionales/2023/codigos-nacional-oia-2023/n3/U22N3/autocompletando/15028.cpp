#include <string>
#include <vector>

using namespace std;

int autocompletando(int K, vector<string> &r1, vector<string> &r2, vector<string> &r3, string &texto) {

    bool band='F';
    vector<string>r4;
    int kaux= r1.size()-K;
    
    for(int j=0; j<r1.size(); j++){ 
        for(int h=0; h<r2.size(); h++){
            while ((r1[j+1],r2[h+1])<(r1[j],r2[h])){
                for(int g=0; g<K-kaux; g++){
                    for(int s=0; s<K; s++){
                        r4[s]=r1[j]+r2[h]+r3[g];
                    }
                }
            }
        }
    }
    band='T';
    if(band='T'){
        return 1;
    } else
    return 0;
}    