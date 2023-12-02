#include <string>
#include <vector>

using namespace std;

int chocolates(int K, vector<int> &x) {
    int r=0;

    for(int i=0;i<x.size();i++){
    r=r+x[i];
    }
   
    int r2 = r;
    
    r=r/K; //6

    if( r*K>r2){
        r--;
        if(r==0){
        r++;
        }
         
    }
        
    

    

    return r;
}
