#include <string>
#include <vector>

using namespace std;

int predictivo(vector<string> &r1, vector<string> &r2, vector<string> &r3, string &texto) {
   int sepuede=0;
   string temp;
  vector <vector<string>> apa;
  apa.resize(r1.size()*(r2.size()*r3.size()));
  for(int i=0; i<r1.size();i++){
    apa[0][i]=r1[i];
    apa[1][i]=r2[i];
    apa[2][i]=r3[i];
  }
  
  
   for(int u=0; u<texto.size();u++){
    if(texto[u]!=' ')
    temp=temp+texto[u];
    else if (texto[u]==' ')
    {
        break;
    }
    
   }
  for(int i=0;i<r1.size()*r1.size();i++){
    for(int u=0; u<texto.size();u++){
    if(texto[u]!=' ')
    temp=temp+texto[u];
    else if (texto[u]==' ')
    {
        break;
    }
   for (int i = 0; i < r1.size()*r2.size()*r3.size(); i++)
    {
    if(r1[i]==temp){
        if(r2[i]==temp){
         sepuede++;
          temp.clear();
          
         if (r3[i]==temp)
         {
            sepuede++;
             temp.clear();
         }
         temp.clear();
  }}}}
 if (sepuede>=1)
    return 1;
else
return 0;
}
  
  
  
   /* for(int i=0; i<texto.size()*texto.size();i++){
     for(int u=0; u<texto.size()*texto.size();u++){
      if(texto.size()==2){
         if(texto==r1[i])
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
*/



