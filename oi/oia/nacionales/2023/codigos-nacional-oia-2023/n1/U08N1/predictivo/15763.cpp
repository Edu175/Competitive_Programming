#include <string>
#include <vector>
#include <iostream>

using namespace std;

int predictivo(vector<string> &r1, vector<string> &r2, vector<string> &r3, string &texto) {
    int r=0;

 int y=0;
 int t=0;
 int u=0;
 int k=0;
 int p=0;

    for(int i=0;i<texto.size()+1;i++){
            for(int j=0;j<r1.size()+1;j++){
            if(texto[j]==r1[i][j]){
             y++;
            if(y==r1.size()){
            p=1;
            break;
            }

            }
        
            }
            if(p==1){
            for(int j=0;j<r2.size()+1;j++){
            if(texto[j]==r2[i][j]){
            t++;
            if(t==r2.size()){
            k=1;
            break;
            }

            }
        
            }
            }
            if(k==1){
            for(int j=0;j<r3.size()+1;j++){
            if(texto[j]==r3[i][j]){
            u++;
            if(u==r3.size()){
            r=1;
            break;
            }

            }
        
            }
            }
    }
    

    return r;
}
