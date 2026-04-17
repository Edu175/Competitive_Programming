#include <string>
#include <vector>

using namespace std;

int predictivo(vector <string> &texto, int n, vector <vector <string> >pap ){
   //vector <string> &texto, int n,vector<string> &r1, vector<string> &r2, vector<string> &r3) {
   int sepuede=0;
   for(int i=0; i<n*n;i++){
     for(int u=0; u<n*n;u++){
      if(texto.size()==2){
         if(texto[0]==pap[i][u])
          if(texto[1]==pap[i][u])
            sepuede++;
}      
      else if(texto.size()==3){
            if(texto[1]==pap[i][u])
          if(texto[2]==pap[i][u])
            sepuede++;
      }    
}}
if (sepuede>=1)
   return 1;
else
   return 0;
}
