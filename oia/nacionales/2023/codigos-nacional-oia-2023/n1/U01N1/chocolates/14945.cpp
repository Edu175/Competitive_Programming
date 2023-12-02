#include <iostream>
#include <vector>

using namespace std;

int chocolates(int K, vector<int> x){
  vector<int> nuevo = x;
  int cantidad = 0;
  if(K != 1){
    while(nuevo.size() > K){
      nuevo[0]--;
      nuevo[1]--;
      nuevo[2]--;
      cantidad++;
      for(int i = 0; i < nuevo.size(); i++){
        if(nuevo[i] == 0) {
          nuevo.erase(nuevo.begin() + i, nuevo.begin() + i + 1);
        }
      }
      cout << "nuevo:" << endl;
      for(int i : nuevo) cout << i << endl;
    }
    while(nuevo[0] != 0 && nuevo[1] != 0 && nuevo[2] != 0){
      nuevo[0]--;
      nuevo[1]--;
      nuevo[2]--;
      cantidad++;
      cout << "nuevo:" << endl;
      for(int i : nuevo) cout << i << endl;
    }
  }
  else{
    for(int i : nuevo){
      cantidad += i;
    }
  }
  return cantidad;
}

int main(){
  cout << chocolates(3, {3, 4, 5}) << endl;
  return 0;
}
