#include <string>
#include <vector>

using namespace std;

vector<int> hoteles(vector<int>& padre, vector<int>& tipo, vector<int>& nodo) {
  int Q=tipo.size(), i, N;
  int P=padre.size();
  vector<int> Modo(P+1,-1);
  vector<int> rta(Q, 0);

  for (i=0; i<Q; i++){
      N = nodo[i];
      if (nodo[i]=0){
          if (Modo[N]!=tipo[i]){
              Modo[N]=tipo[i];
              rta[i]+=1;
          }
          else{
              if (Modo[N]==tipo[i]){
                  rta[i]+=0;
              }
          }
      }
      else{
          if (nodo[i]!=0){
              if (Modo[N]!=tipo[i]){
                  if (Modo[0]!=1){
                      Modo[N]=tipo[i];
                      rta[i]+=1;
                  }
              }
              else{
                  rta[i]+=0;
              }
          }
      }

  }
  return rta;
}
