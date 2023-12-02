#include <bits/stdc++.h>

using namespace std;

const int WIFI = 0;
const int RET = 1;

bool check(vector<int>& p, int nodo, vector<int>& modo, vector<vector<int>>& adj){
    int padre = p[nodo];
    while(padre != 0){
      if(modo[padre] == 0){
        return false;
      }
      padre = p[padre];
    }
    if(modo[padre] == 0) return false;
    queue<int> q;
    for(auto c: adj[nodo]){
      q.push(c);
    }
    while(!q.empty()){
      int curr = q.front(); q.pop();
      if(modo[curr] == 0){
        return false;
      }
      for(auto c: adj[curr]){
        q.push(c);
      }
    }
    return true;

}

vector<int> hoteles(vector<int>& padre, vector<int>& tipo, vector<int>& nodo) {
  vector<int> ret(tipo.size());
  vector<vector<int>> adj (padre.size()+1);
  for(int i = 0; i < padre.size(); i++){
    adj[padre[i]].push_back(i+1);
  }
  vector<int> modo(padre.size()+1, 1);
  for(int i = 0; i < tipo.size(); i++){
    if(tipo[i] == modo[nodo[i]])ret[i] = (0);
    else if(tipo[i] == 1){
      ret[i] = 1;
      modo[nodo[i]] = tipo[i];
    }
    else{
      if(check(padre, nodo[i], modo, adj)){
        modo[nodo[i]] = !modo[nodo[i]];
        ret[i] = 1;
      }else{
        ret[i] = 0;
      }
    }
  }
  return ret;
}
