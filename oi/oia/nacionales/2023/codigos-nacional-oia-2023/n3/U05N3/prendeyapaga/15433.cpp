#include <string>
#include <vector>

using namespace std;

vector<int> hoteles(vector<int>& padre, vector<int>& tipo, vector<int>& nodo) {
  int Q=tipo.size(), i, N;
  int P=padre.size();
  if (P>0){
      P+1;
  }
  vector<int> modo(P,-1);
  vector<int> rta(Q, 0);

  for (i=0; i<Q; i++){
      N = nodo[i];
      if (modo[0]!=1){
      if (N!=0){
          if (modo[0]!=0){
              if (modo[N]!=tipo[i]){
                  modo[N]=tipo[i];
                  rta[i]=1;
              }
          }
      }
      else{
          if (modo[0]!=tipo[i]){
              modo[0]=tipo[i];
              rta[i]=1;
          }
          else{
              modo[0]=tipo[i];
          }
      }
      }
  }
  return rta;
}
