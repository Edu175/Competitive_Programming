#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int chocolates(int K, vector<int> &x){
  vector<int> nuevo = x;
  int cantidad = 0;
  if(K != 1){
    while(nuevo.size() > K - 1){
      sort(nuevo.begin(), nuevo.end());
      reverse(nuevo.begin(), nuevo.end());
      nuevo[0]--;
      nuevo[1]--;
      nuevo[2]--;
      cantidad++;
      for(int i = 0; i < nuevo.size(); i++){
        if(nuevo[i] == 0) {
          nuevo.erase(nuevo.begin() + i, nuevo.begin() + i + 1);
        }
      }
    }
  }
  else{
    for(int i : nuevo){
      cantidad += i;
    }
  }
  return cantidad;
}
