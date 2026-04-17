#include <string>
#include <vector>

using namespace std;

int chocolates(int K, vector<int> &x) {
    int r=0;


//if(K!=2){
    for(int i=0;i<x.size();i++){
    r=r+x[i];
    }
   
 
    
    r=r/K; //6

    /*if( r2*K2>r2){
        r--;
        if(r==0){
        r++;
        }
         
    }*/
//}else{

//}
    

    

    return r;
}
