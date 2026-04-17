#include <bits/stdc++.h>

using namespace std;

vector<int> hoteles(vector<int>& padre, vector<int>& tipo, vector<int>& nodo) {
    vector<int> ret;
    set<int> s;
    vector<bool> modos (padre.size()+1, true);
    bool canTR = true;
    for(int i = 0; i < nodo.size(); i++){
      if(nodo[i] == 0){
        if(tipo[i] == 0){
          if(canTR){
            modos[0] = false;
            ret.push_back(1);
          }else{
            ret.push_back(0);
          }
        }else if(modos[0] == 0){
          modos[0] = true;
          ret.push_back(1);
        }else{
          ret.push_back(0);
        }

      }
      else{
        if(modos[0] == 1 && modos[nodo[i]] != tipo[i]){
          modos[nodo[i]] = !tipo[i];
          ret.push_back(1);
        }else{
          ret.push_back(0);
        }
        if(modos[nodo[i]] == 0){
          s.insert(nodo[i]);
        }else{
          s.erase(nodo[i]);
        }
        canTR = !s.empty();
      }

    }
    return ret;
}
