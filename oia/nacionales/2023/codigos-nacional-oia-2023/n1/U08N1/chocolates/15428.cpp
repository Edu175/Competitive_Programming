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

    /*int e=0;

    int m = r;

    double r2(r);

    r2--;


    for(int i=0;i<m;i++){
     




    }

    if(e=1){
        int r3(r);
        r3--;
    }*/
    
    r--;
    r/2;
}

    

    

    return r;
}
