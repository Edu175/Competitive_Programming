#include <bits/stdc++.h>

using namespace std;

vector<string> vectorify(string& texto){
  string w = "";
  vector<string> ret;
  for(auto& c: texto){
    if(c == ' '){
      ret.push_back(w);
      w = "";
    }else{
      w = w + c;
    }
  }
  ret.push_back(w);
  return ret;
}

int autocompletando(int K, vector<string> &r1, vector<string> &r2, vector<string> &r3, string &texto) {
    map<pair<string, string>,set<string>> mp;
    for(int i = 0; i < r1.size(); i++){
      mp[{r1[i], r2[i]}].insert(r3[i]);
    }
    int n = 2;
    vector<string> vtext = vectorify(texto);
    for(int i = 2; i < vtext.size(); i++){
      if(!mp[{vtext[i-2], vtext[i-1]}].count(vtext[i])){
        n++;
      }
    }
    return n <= K;

}
