#include <string>
#include <vector>

using namespace std;

int chocolates(int K, vector<int> &x) {
    int r=0;


if(K!=2){
    for(int i=0;i<x.size();i++){
    r=r+x[i];
    }

    r=r/K; 
}else{
   for(int i=0;i<x.size();i++){
    r=r+x[i];
    }

    r=r/K; 
    r--;
}

    

    

    return r;
}
